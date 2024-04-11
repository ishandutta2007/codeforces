#include<iostream>
#include<bitset>
#include<cstdio>
using namespace std;
int n,m;
bitset<500>a[500],b[500],now;
main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<500;i++)now[i]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int x;scanf("%d",&x);
			a[i][j]=x;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int x;scanf("%d",&x);
			b[i][j]=x;
		}
	}
	bool flag=0;
	for(int i=0;i<n;i++)
	{
		now^=a[i]^b[i];
		if(now.count()%2==1)
		{
			flag=1;
			break;
		}
	}
	flag|=now.any();
	puts(flag?"No":"Yes");
}