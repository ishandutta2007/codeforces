#include<iostream>
using namespace std;
int n,m;
main()
{
	cin>>n>>m;
	for(int i=0;i<1000;i++)cout<<(i%2?"5":"4");
	cout<<endl;
	for(int i=0;i<999;i++)cout<<(i%2?"4":"5");
	cout<<"5"<<endl;
}