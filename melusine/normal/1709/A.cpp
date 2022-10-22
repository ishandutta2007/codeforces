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
bool vis[5];
int main()
{
	int t,x,a,b,c,sl;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		x=read();
		a=read();
		b=read();
		c=read();
		sl=0;
		vis[0]=true;
		vis[1]=vis[2]=vis[3]=false;
		while(vis[x]==false)
		{
			vis[x]=true;
			sl++;
			if(sl==3)break;
			if(x==1)x=a;
			else if(x==2)x=b;
			else x=c;
		}
		if(sl==3)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}