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
int a[100005],pos[100005];
bool bi(int x,int y)
{
	return a[x-1]-a[x]<a[y-1]-a[y];
}
int main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read(),pos[i]=i;
		sort(pos+1,pos+n+1,bi);
		for(int i=1;i<=n;i++)printf("%d ",pos[i]);
		printf("\n");
	}
	return 0;
}