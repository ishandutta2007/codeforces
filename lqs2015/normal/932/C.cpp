#include<iostream>
#include<cstdio>
using namespace std;
int n,a,b,x,y,cnt,pp;
int main()
{
	cin>>n>>a>>b;
	x=y=-1;
	for (int i=0;i<=n/a;i++)
	{
		if ((n-i*a)%b==0)
		{
			x=i;
			y=(n-i*a)/b;
			break;
		}
	}
	if (x==-1) 
	{
		cout<<-1<<endl;
		return 0;
	}
	cnt=1;
	for (int i=1;i<=x;i++)
	{
		if (!a) break;
		pp=cnt;cnt++;
		for (int j=1;j<a;j++)
		{
			printf("%d ",cnt);
			cnt++;
		}
		printf("%d ",pp);
	}
	for (int i=1;i<=y;i++)
	{
		if (!b) break;
		pp=cnt;cnt++;
		for (int j=1;j<b;j++)
		{
			printf("%d ",cnt);
			cnt++;
		}
		printf("%d ",pp);
	}
}