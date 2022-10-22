#include <bits/stdc++.h>
using namespace std;
#define N 405
#define M 200005
#define MOD 998244353
#define pb push_back
#define set(a,vl) memset(a,vl,sizeof(a))
int n,m,gr,cnt0,inv[N],q[N],dst[N],vs1[M],vs2[N],cnt[N],dp[N],dp0[N];
bool vs3[N];vector<int> e[N],vc[N][N];
int f(int u,int v) {return (u-1)*n+v;}
void bfs(int S,vector<int> vc[])
{
	set(dst,-1);dst[S]=0;q[0]=2;q[1]=1;q[++q[1]]=S;
	while(q[0]<=q[1])
	{
		int u=q[q[0]++];
		for(int i=0,v;i<e[u].size();++i)
		{
			v=e[u][i];if(dst[v]==-1) dst[v]=dst[u]+1,q[++q[1]]=v;
			if(dst[v]==dst[u]+1) vc[v].pb(u);
		}
	}
}
void dfs(int u1,int u2,int u)
{
	if(vs3[u]) return;vs3[u]=1;
	int w=cnt[u]?inv[cnt[u]]:1,d=cnt[u]?0:1;
	for(int i=0,v;i<vc[u1][u].size();++i)
	{
		v=vc[u1][u][i];
		if(vs1[f(v,u)]==gr)
		{
			dfs(u1,u2,v);if(dp0[v]+d>dp0[u]) dp0[u]=dp0[v]+d,dp[u]=0;
			if(dp0[u]==dp0[v]+d) dp[u]=(dp[u]+1ll*dp[v]*w)%MOD;
		}
	}
}
int slv(int u1,int u2)
{
	++gr;cnt0=0;
	for(int i=1;i<=n;++i)
		cnt[i]=vs2[i]=vs3[i]=dp[i]=dp0[i]=0;dp[u1]=vs3[u1]=1;
	for(int i=1,v;i<=n;++i)
	{
		for(int j=0;j<vc[u1][i].size();++j) vs2[vc[u1][i][j]]=i;
		for(int j=0;j<vc[u2][i].size();++j)
		{v=vc[u2][i][j];vs1[f(i,v)]=gr;if(vs2[v]==i) ++cnt[i];}
		if(cnt[i]) dp[u1]=1ll*dp[u1]*cnt[i]%MOD;else ++cnt0;
	}dp0[u1]=1;dfs(u1,u2,u2);return dp0[u2]==cnt0?dp[u2]:0;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)
		inv[i]=i==1?1:1ll*inv[MOD%i]*(MOD-MOD/i)%MOD;
	for(int i=1,u,v;i<=m;++i)
		scanf("%d %d",&u,&v),e[u].pb(v),e[v].pb(u);
	for(int i=1;i<=n;++i) bfs(i,vc[i]);
	for(int i=1;i<=n;++i,puts("")) for(int j=1;j<=n;++j)
		printf("%d ",slv(i,j));return 0;
}