#include<iostream>
#include<cstdio>
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
int main()
{
	int t,n,m,sx,sy,d;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		sx=read();
		sy=read();
		d=read();
		if(sx-1<=d&&sy-1<=d)printf("-1\n");
		else if(n-sx<=d&&m-sy<=d)printf("-1\n");
		else if(sx-1<=d&&n-sx<=d)printf("-1\n");
		else if(sy-1<=d&&m-sy<=d)printf("-1\n");
		else printf("%d\n",n+m-2);
	} 
	return 0;
}