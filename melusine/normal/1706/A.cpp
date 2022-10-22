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
int qans[10005];
int a[100005];
int main()
{
	int t,n,m;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		for(int i=1;i<=m;i++)qans[i]=2;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			if(a[i]>m+1-a[i])a[i]=m+1-a[i];
			if(qans[a[i]]==2)qans[a[i]]=1;
			else qans[m+1-a[i]]=1;
		}
		for(int i=1;i<=m;i++)
		{
			if(qans[i]==1)printf("A");
			else printf("B");
		}
		printf("\n");
	}
	return 0;
}