#include <iostream>
#include <stdio.h>
#include <map>
#include <stdlib.h>
using namespace std;
int n,l,x,y;
int a[100005];
map<int,bool> mp;

void check(int x,int y)
{
	if(x>l || x<0) return;
	if(mp[x-y] || mp[x+y])
	{
		cout<<1<<endl<<x<<endl;
		exit(0);
	}
}

int main()
{
	cin>>n>>l>>x>>y;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		mp[a[i]]=true;
	}
	bool fx=false,fy=false;
	for(int i=0;i<n;i++)
	{
		fx|=mp[a[i]-x];
		fx|=mp[a[i]+x];
		fy|=mp[a[i]-y];
		fy|=mp[a[i]+y];
	}
	if(fx && fy)
	{
		cout<<0<<endl;
	}
	else if(fx)
	{
		cout<<1<<endl<<y<<endl;
	}
	else if(fy)
	{
		cout<<1<<endl<<x<<endl; 
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			check(a[i]-x,y);
			check(a[i]+x,y);
			check(a[i]+y,x);
			check(a[i]-y,x);
		}
		cout<<2<<endl<<x<<' '<<y<<endl;
	}
	return 0;
}