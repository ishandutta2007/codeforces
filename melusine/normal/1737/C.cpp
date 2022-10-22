#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define int unsigned long long
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
signed main()
{
	int t,n,r1,c1,r2,c2,r3,c3,x,y;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		r1=read();
		c1=read();
		r2=read();
		c2=read();
		r3=read();
		c3=read();
		x=read();
		y=read();
		int zx=r1+r2+r3-max(max(r1,r2),r3)-min(min(r1,r2),r3);
		int zy=c1+c2+c3-max(max(c1,c2),c3)-min(min(c1,c2),c3);
		if(x%2!=zx%2&&y%2!=zy%2)
		{
			printf("NO\n");
			continue;
		}
		if((zx==1||zx==n)&&(zy==1||zy==n))
		{
			if(x==zx||y==zy)printf("YES\n");
			else printf("NO\n");
			continue;
		}
		printf("YES\n");
	}
	return 0;
}