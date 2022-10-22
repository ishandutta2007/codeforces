#include<iostream>
#include<cstdio>
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
int fa[200005],cd[200005];
struct bbian
{
	int u,v,nex;
}a[800004];
int head[200005],tmp;
void addb(int x,int y)
{
	a[++tmp].u=x;
	a[tmp].v=y;
	a[tmp].nex=head[x];
	head[x]=tmp;
}
int qz[200005];
int qy[200005],cnt;
int dp[200005],zj[200005];
bool bi(int x,int y)
{
	return x>y;
}
void dfs(int x,int f,int sl)
{
	qz[x]+=qz[f];
	vector<int>v;
	int het=0;
	for(int i=head[x];i;i=a[i].nex)
	{
		if(a[i].v==f)continue;
		dfs(a[i].v,x,sl/cd[x]);
		het+=dp[a[i].v];
		v.push_back(zj[a[i].v]);
	}
	if(cd[x]==0)
	{
		dp[x]=sl*qz[x];
		zj[x]=qz[x];
		return;
	}
	sort(v.begin(),v.end(),bi);
	for(int i=0;i<=sl%cd[x]-1;i++)
	{
		het+=v[i];
	}
	dp[x]=het;
	zj[x]=v[sl%cd[x]];
	return;
}
signed main()
{
	int t,n,k,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		for(int i=1;i<=n;i++)head[i]=0,cd[i]=0;
		tmp=0;
		for(int i=1;i<=n-1;i++)
		{
			fa[i+1]=read();
			cd[fa[i+1]]++;
			addb(fa[i+1],i+1);
		}
		for(int i=1;i<=n;i++)qz[i]=read();
		cnt=0;
		dfs(1,0,k);
		printf("%lld\n",dp[1]);
	}
	return 0;
}