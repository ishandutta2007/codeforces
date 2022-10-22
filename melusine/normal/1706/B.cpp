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
int qans[200005];
int a[200005],pre[200005];
int main()
{
	int t,n,m;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)qans[i]=0,pre[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(pre[a[i]]==0||(i-pre[a[i]])%2==1)qans[a[i]]++;
			pre[a[i]]=i;
		}
		for(int i=1;i<=n;i++)printf("%d ",qans[i]);
		printf("\n");
	}
	return 0;
}