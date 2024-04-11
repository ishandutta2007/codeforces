#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	bool pro;
	int i;
	cin>>i;
	if(i==12)pro=true;
	else pro=false;
	int hou,min;
	char konma;
	cin>>hou>>konma>>min;
	if(min>=60)min%=60;
	if(pro)
	{
		if(hou==0)hou=10;
		else if(hou>=13)
		{
			if(hou%10!=0)hou%=10;
			else hou=10;
		}
	}
	else
	{
		if(hou>=24)hou%=10;
	}
	cout<<setfill('0')<<setw(2)<<right<<hou<<konma<<setfill('0')<<setw(2)<<right<<min<<endl;
	return 0;
}