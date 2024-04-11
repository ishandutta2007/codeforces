#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int a[]={2,3,4,5,7,9,11,13,17,19,23,25,29,31,37,41,43,47,49,53};
string n;
int g;
int main()
{
	fflush(stdout); 
	for (int i=0;i<20;i++)
	{
		cout<<a[i]<<endl;
		cin>>n;
		if (n=="yes") g++;
		if (g==2) 
		{
			cout<<"composite"<<endl;
			return 0;
		}
	}
	cout<<"prime"<<endl;
	return 0;
}