#include<iostream>
using namespace std;
int x,y,a,b;
main()
{
	cin>>x>>y>>a>>b;
	x+=a*8;
	if(x>=y)
	{
		cout<<0<<endl;
		return 0;
	}
	x-=b*12;
	if(a<=b)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int k=1;;k++)
	{
		x+=a*12;
		if(x>=y)
		{
			cout<<k<<endl;
			return 0;
		}
		x-=b*12;
	}
}