#include<iostream>
using namespace std;
int x,y,z,a,b,c;
main()
{
	cin>>x>>y>>z>>a>>b>>c;
	if(a<x)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	a-=x;
	if(a+b<y)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	if(a+b-y+c<z)
	{
		cout<<"NO"<<endl;
	}
	else
	{
		cout<<"YES"<<endl;
	}
}