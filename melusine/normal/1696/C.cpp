#include<iostream>
#include<cstdio>
#include<cstring>
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
int a[100005],tsl[100005];
int main()
{
	int t,n,m,now,x,xsl;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		a[n+1]=0;
		tsl[n+1]=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			tsl[i]=1;
			while(a[i]%m==0)
			{
				a[i]/=m;
				tsl[i]*=m;
			}
		}
		now=1;
		bool flag=true;
		int k;
		k=read();
		for(int i=1;i<=k;i++)
		{
			x=read();
			xsl=1;
			while(x%m==0)
			{
				x/=m;
				xsl*=m;
			}
			while(xsl>0)
			{
				if(a[now]!=x||now==n+1)
				{
					flag=false;
					break;
				}
				int sth=min(tsl[now],xsl);
				xsl-=sth;
				tsl[now]-=sth;
				if(tsl[now]==0)now++;
			}
		}
		if(flag==false||now!=n+1)printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}