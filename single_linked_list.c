#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


//Creating custom function for buffer clean
void clean_stdin(void)
{
	int c;
	do{
		c=getchar();
	}while(c!='\n' && c!=EOF);

}
//Creating Linked List Structure
struct node{
	int data;
	struct node *next;
};
typedef struct node node;  //Making Alias for structure

//Declaring Functions
node* create();
void display(node *);
void display_rev(node *);
node* insert_beg(node*);
node* insert_end(node*);
node* insert_pos(node *);
node* del_beg(node *);
node* del_end(node *);
node* del_pos(node *);
int count(node*);

//Main function
int main(){
	int a;
	node* head=NULL;
	printf("Linked List\n");
	printf("Select your Chioce from Menu below:\n");
	while(1)
	{ 
		printf("\n----------------------------------------------\n");
	printf("\n1. Create LL\n2. Display LL\n3. Display in reverse Order\n4. Insert at beginning\n5. Insert at End\n6. Insert at specified position\n7. Delete from beginning\n8. Delete at end\n9. Delete at specified position\n10. Exit \nYour Choice--:");

	scanf("%d",&a);
printf("\n----------------------------------------------\n");

switch(a){
 	default:   
		printf("Invalid choice, re-enter value\n");
                break;

	case 1:
		head=create();
		printf("\nLL created successfully\n");
		break;
	case 2:
		display(head);
		break;
	case 3:
		display_rev(head);
		break;
	case 4:
		head=insert_beg(head);
		break;
	case 5:
		head=insert_end(head);
		break;
	case 6:
		head=insert_pos(head);
		break;
	case 7:
		head=del_beg(head);
		break;
	case 8:
		head=del_end(head);
		break;
	case 9:
		head=del_pos(head);
		break;
	case 10:
		exit(0);
		break;
	}
    }
}


node* create(){
	node* head=NULL;
	node* tail=NULL;
	int val;
	char ch;
	node* temp=NULL;
	node* temp1=NULL;
	temp=(node*)malloc(sizeof(node));
	printf("Enter data to be inserted:\n");
	scanf("%d",&val);
	temp->data=val;
	temp->next=NULL;
	head=temp;
	tail=temp;
	printf("Do you want to enter more data (y/n)?");
	clean_stdin();
	scanf("%c",&ch);
	while(ch=='y' || ch=='Y')
	{
		temp1=(node*)malloc(sizeof(node));
		printf("Enter the data:\n");
		scanf("%d",&val);
		temp1->data=val;
		temp1->next=NULL;
		tail->next=temp1;
		tail=temp1;
		 printf("Do you want to enter more data (y/n)?");
		 clean_stdin();
		 scanf("%c",&ch);	
	}
	return head; 
}


void display(node* head){
	     node* temp=head;
	     if(temp==NULL){
		     printf("Empty List!\n");
	             return;}
	     while(temp!=NULL)
	     {
		     if(temp->next==NULL)
		     {
			     printf("%d ",temp->data);
		     }
		     else{
		     printf("%d->",temp->data);
		     }
		     temp=temp->next;
	     }
	     printf("\n");
}

void display_rev(node *head){
		node* temp=head;
		 if(temp==NULL){
			return;
		 }
		 else
		{
			display_rev(temp->next);
			printf("%d->",temp->data);
		}
}

node* insert_beg(node* head){
	node* ptr=head;
	node* new;
	if(ptr==NULL)
		printf("Empty List!\n");
	else
	{
		new=(node*)malloc(sizeof(node));
		new->next=NULL;
		printf("Enter data:\n");
		scanf("%d",&new->data);
		new->next=ptr;
		head=new;
	}
	return head;
	       // printf("Function Incomplete:Insert at beginning\n");
}

node* insert_end(node* head){
	node *ptr=head;
	node *postptr=NULL;
	if(ptr==NULL)
	{	printf("Empty List!\n");
		return (ptr);
	}
	else{
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	postptr=(node*)malloc(sizeof(node));
	printf("Enter the data to insert:  \n");
	scanf("%d",&postptr->data);
	postptr->next=NULL;
	ptr->next=postptr;	
	}
	return head;
	       // printf("Function Incomplete:Insert at end\n");
}

node* insert_pos(node* head){
	node *ptr=head,*postptr=head;
	int pos,size;
	int counter=1;
	size=count(ptr);
	printf("Enter the position you want to insert the data to:\n");
	 scanf("%d",&pos);
	 if(pos<=0||pos>size)
		 printf("Invalid Position\n");
	 else{
	  	if(pos==1)
		{
			if(ptr==NULL)
				printf("List Empty!\n");
			else
				insert_beg(ptr);
		}
		else if(pos==size)
			insert_end(ptr);
		else{
			while(counter!=(pos-1))
			{
				ptr=ptr->next;
				counter++;
			}
			postptr=(node*)malloc(sizeof(node));
			postptr->next=NULL;
			printf("Enter the data to be inserted at position %d:\n",pos);
			scanf("%d",&postptr->data);
			postptr->next=ptr->next;
			ptr->next=postptr;
		 	return head;
		}

	 }


	//        printf("Function Incomplete:Insert at specified position\n");
}

node* del_beg(node* head){
	node* ptr1=head;
	if(ptr1==NULL)
	{
		printf("Empty List!\n");
	}
	else{
		head=ptr1->next;
		ptr1->next=NULL;
		free(ptr1);
		ptr1=NULL;
	}
	return head;
}

node* del_end(node *head){
	node* ptr=head;
	node *preptr=head;
	if(ptr==NULL)
	{
		printf("Empty List!\n");
	}
	else if(ptr->next==NULL)
	{
		free(ptr);
		ptr=NULL;
		head=NULL;
	}
	else
	{
		
	while(ptr->next!=NULL)
	{
		preptr=ptr;
		ptr=ptr->next;

	}
     	 preptr->next=NULL;
	 free(ptr);
	 ptr=NULL;
	}
	return head;
}

node* del_pos(node* head){
	node* ptr=head;
	node* preptr=head;
	int size=count(ptr);
	int pos,counter=1;
	if(ptr==NULL)
		printf("Empty List!");
	else{
	printf("Enter the position from where data is to be deleted:\n");
	scanf("%d",&pos);
	if(pos<=0||pos>size)
	{
	 printf("Invalid Posiion\n");
	}
	else
	{
		if(pos==1){
			head=del_beg(ptr);
		}
		else if(pos==size){
			head=del_end(ptr);
		}
		else{
	 	while(counter!=pos)
		{
			preptr=ptr;
			ptr=ptr->next;
			counter++;
		}
		preptr->next=ptr->next;
		free(ptr);
		ptr=NULL;
		}
	}
	}
	return head;
	       // printf("Function Incomplete:Delete from specied position\n");
}



int count(node* head){
	node* ptr=head;
 	int counter=1;
	if(ptr==NULL)
	{
		counter=0;
	}
	else{
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
			counter++;
		}
	}
	return counter;
}
