#include <iostream>
using namespace std;
class operation {
public:
    int numbers;
    operation*list1;
    operation()
    {
        numbers = 0;
        list1 = NULL;
    }
    operation(int numbers)
    {
        this->numbers = numbers;
        this->list1 = NULL;
    }
	~operation()
	{
	}
};
class original_list {
    operation* head;
  
public:
    orignal_list() { head = NULL; }
    int add_elements(int numbers)
	{
    operation* newNumber = new operation (numbers);
    if (head == NULL) {
        head = newNumber;
        return 0;
    }
    operation*num2 = head;
    while (num2->list1 != NULL) {
        num2 = num2->list1;
    }
    num2->list1 = newNumber;
}        
    void print_elements()
    {
    operation* num2 = head;
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }
  
    while (num2!= NULL) {
        cout << num2->numbers<< " ";
        num2 = num2->list1;
    }
}
bool search(operation*head,int a)
{
	operation*num2= head;
	while( head!= NULL){
		if (num2->numbers==a)
		return true;
		num2= head->list1;
	num2=num2->list1;
}
	return false;
}
	void insertFront(operation* head,operation*tail, int numbers){

    operation* new_node = new operation();
    new_node->numbers = numbers;
    new_node->list1=head;
    head = new_node;
    tail=new_node;
    cout << "Inserted Item: " << new_node<< endl;
}
void idelete(operation*head,int a){
	if(head->numbers==a){
		delete head;
		head=head->list1;
		return;
		}
		else{
		operation*num2=head;
		while(num2!=NULL)
		{
	/*		operation*del=num2->list1->list1;
			num2->list1=del; */
			if(num2->numbers==a){
				delete num2->list1;
					return ;
			}
			operation*num2=num2->list1;
		}
		/*num2->list1;*/
	}
}
}; 
int main()
{
	operation*head=NULL;
	int a,choice;
	int result,new_node=2;
    original_list list;
    list.add_elements(10);
    list.add_elements(20);
    list.add_elements(30);
    list.add_elements(25);
    list.add_elements(12);
    list.add_elements(45);
    list.add_elements(23);
    list.add_elements(87);
    cout << "Elements of the list are: "<<endl;
    list.print_elements();
    cout << endl;
    cout << endl;
    cout<<"further manupilations"<<endl<<endl;
    cout<<"choose your operation between"<<endl<<endl<< "1:REMOVING ELEMENTS"<<endl<<endl<<"2:SEARCHING FOR AN ELEMENT"<<endl<<endl<<"3:ADDING ELEMENTS TO TAIL"<<endl<<endl;
	cout<<"4:ADDING ELEMENTS TO HEAD"<<endl<<endl;
    cin>>choice;
    switch(choice) {
      case 1 :
         cout << "Removing Elements" << endl; 
         cout << "available list:"<<endl;;
		 list.print_elements();
         cout<<"enter an element you want deleted from the above list"<<endl;
         cin>>a;
         list.idelete(head,a);
         cout<<"updated list:"<<endl;
         list.print_elements();
         break;
      case 2 :
      	cout<<"searching for elements"<<endl;
      	 cout<<"enter the number you want to search for"<<endl;
    cin>>a;
    list.search(head,a)?
	cout<<"yes your number is part of the list":cout<<"no your number isn't part of the list ";
    break;
      case 3 :
         cout << "Adding elements to tail" << endl;
         cout<<"enter an element"<<endl<<endl;
    cin>>new_node;
    list.add_elements(new_node);
    cout<<"updated list"<<endl;
    list.print_elements();
         break;
      case 4 :
         cout << "Adding elements to head" << endl;
         operation*tail;
         cin>>new_node;
         list.add_elements(new_node);
         cout<<"updated list"<<endl;
         list.print_elements();
         break;
      default :
      	cout<<"invalid choice"<<endl;
      }

    return 0;
}
