#include<iostream>
using namespace std;
int n,p,a,pp=-1;
const string out="Infinite";
main()
{
	cin>>n>>p;
	long ans=0;
	for(int i=1;i<n;i++)
	{
		cin>>a;
		if(p==1)
		{
			if(a==1)
			{
				cout<<out<<endl;
				return 0;
			}
			else if(a==2)
			{
				ans+=pp==3?2:3;
			}
			else if(a==3)
			{
				ans+=4;
			}
		}
		else if(p==2)
		{
			if(a==1)
			{
				ans+=3;
			}
			else if(a==2)
			{
				cout<<out<<endl;
				return 0;
			}
			else if(a==3)
			{
				cout<<out<<endl;
				return 0;
			}
		}
		else if(p==3)
		{
			if(a==1)
			{
				ans+=4;
			}
			else if(a==2)
			{
				cout<<out<<endl;
				return 0;
			}
			else if(a==3)
			{
				cout<<out<<endl;
				return 0;
			}
		}
		pp=p;
		p=a;
	}
	cout<<"Finite"<<endl<<ans<<endl;
}