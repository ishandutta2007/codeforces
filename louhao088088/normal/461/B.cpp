#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int cnt=0,head[200005],x,y,n,a[200005],dp[200005][2],mod=1e9+7,ans=1;
struct node
{
	int v,nex;
}e[200005];
void add(int u,int v)
{
	e[++cnt].v=v,e[cnt].nex=head[u],head[u]=cnt;
}
void dfs(int x,int fa)
{
	int tot=0;dp[x][a[x]]=1;
	for(int i=head[x];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==fa)
		{
			continue;
		}
		dfs(v,x);
		if(a[x]==0)
		{
			dp[x][1]=(dp[x][1]*(dp[v][0]+dp[v][1])%mod+dp[x][0]*dp[v][1]%mod);
			dp[x][0]=dp[x][0]*(dp[v][0]+dp[v][1])%mod;
		}
		else if(a[x]==1)dp[x][1]=dp[x][1]*(dp[v][0]+dp[v][1])%mod;
	}
}
signed main()
{
	n=read();
	for(int i=2;i<=n;i++)
	{
		x=read(),add(x+1,i),add(i,x+1);
	}
	for(int i=1;i<=n;i++)
		a[i]=read();
	dfs(1,0);
	cout<<dp[1][1]%mod;
	return 0;
}