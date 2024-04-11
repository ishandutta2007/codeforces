#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define int long long
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
int a[200005],pos[200005];
bool vis[200005];
bool bi(int x,int y)
{
	return a[x]+x<a[y]+y;
}
signed main()
{
	int t,n,k,ans=0,pre;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		for(int i=1;i<=n;i++)a[i]=read(),pos[i]=i,vis[i]=false;
		sort(pos+1,pos+n+1,bi);
		for(int i=n-k+1;i<=n;i++)vis[pos[i]]=true;
		ans=0;
		pre=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==false)ans+=a[i]+pre;
			else pre++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}