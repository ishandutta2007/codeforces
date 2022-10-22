#include<iostream>
#include<cstdio>
#include<algorithm>
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
int a[200005];
int jg[200005];
int main()
{
	int ttt,n,m,ans,now;
	ttt=read();
	for(int greg=1;greg<=ttt;greg++)
	{
		n=read();
		m=read();
		for(int i=1;i<=m;i++)a[i]=read();
		sort(a+1,a+m+1);
		for(int i=1;i<=m-1;i++)jg[i]=a[i+1]-a[i]-1;
		jg[m]=a[1]+n-a[m]-1;
		sort(jg+1,jg+m+1);
		ans=n;
		now=0;
		for(int i=m;i>=1;i--)
		{
			//printf("orz%d\n",jg[i]);
			jg[i]=max(jg[i]-2*now,0);
			if(jg[i]==0)continue;
			if(jg[i]==1||jg[i]==2)
			{
				ans--;
				now++;
				continue;
			}
			now+=2;
			ans-=(jg[i]-1);
		}
		printf("%d\n",ans);
	}
}