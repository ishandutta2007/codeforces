#include<iostream>
#include<cstdio>
#include<map>
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
map<int,int>ma;
int a[100005],f[100005];
int main()
{
	int t,n,maxn=0,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		ma.clear();
		maxn=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			ma[a[i]]++;
			maxn=max(maxn,ma[a[i]]);
		}
		ans=0;
		while(1LL*(1<<ans)*maxn<n)ans++;
		printf("%d\n",ans+n-maxn);
	} 
	return 0;
}