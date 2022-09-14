#include<iostream>
using namespace std;
int T,x,y;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>x>>y;
		if((x+y)%2==1)cout<<"-1 -1\n";
		else
		{
			int d=(x+y)/2;
			int nx=0,ny=0;
			nx=d<x?d:x;
			d-=nx;
			ny=d;
			cout<<nx<<" "<<ny<<"\n";
		}
	}
}