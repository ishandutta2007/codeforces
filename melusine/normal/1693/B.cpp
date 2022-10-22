#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define int long long
#define mod 1000000007
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
int fa[1000005];
vector<int>v[1000005];
int ans=0;
int ql[200005],qr[200005],qz[200005];
void dfs(int x,int f)
{
	int het=0;
	for(int i=0;i<v[x].size();i++)
	{
		if(v[x][i]==f)continue;
		dfs(v[x][i],x);
		het+=qz[v[x][i]];
	}
	if(het<ql[x])
	{
		qz[x]=qr[x];
		ans++;
	}
	else qz[x]=min(het,qr[x]);
	return;
}
signed main()
{
	int t,n;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=2;i<=n;i++)fa[i]=read(),v[fa[i]].push_back(i);
		for(int i=1;i<=n;i++)
		{
			ql[i]=read();
			qr[i]=read();
		}
		ans=0;
		dfs(1,0);
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)v[i].clear();
	}
	return 0;
}