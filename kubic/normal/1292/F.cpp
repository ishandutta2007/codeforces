#include <bits/stdc++.h>
using namespace std;
#define N 65
#define M 1<<15
#define MOD 1000000007
#define pb push_back
int n,nw,all,ans=1,a[N],st[N],st1[N],z[N],w[M],dp[M];
int C[N][N],A[N][N];bool vs[N],tg[N];vector<int> e[N];
int add(int x,int y) {x+=y;return x<MOD?x:x-MOD;}
void W(int &x,int y) {x+=y;if(x>=MOD) x-=MOD;}
void dfs(int u)
{
	if(vs[u]) return;vs[u]=1;
	if(tg[u]) st1[++st1[0]]=u;else st[++st[0]]=u;
	for(auto v:e[u]) dfs(v);
}
void FWT_or(int n,int a[])
{
	for(int i=1;i<1<<n;i*=2) for(int j=0;j<1<<n;j+=i*2)
		for(int k=0;k<i;++k) W(a[i+j+k],a[j+k]);
}
void slv()
{
	if(!st[0]) return;nw+=st[0]-1;ans=1ll*ans*C[nw][st[0]-1]%MOD;
	for(int i=1;i<=st[0];++i)
	{
		z[i]=0;
		for(int j=1;j<=st1[0];++j)
			if(!(a[st[i]]%a[st1[j]])) z[i]|=1<<j-1;
	}for(int i=0;i<1<<st1[0];++i) w[i]=0;
	for(int i=1;i<=st[0];++i) ++w[z[i]];
	FWT_or(st1[0],w);dp[all=(1<<st1[0])-1]=1;
	for(int i=(1<<st1[0])-2;i>=0;--i)
	{
		dp[i]=0;
		for(int j=1;j<=st[0];++j) if((!i || i&z[j]) && z[j]&(i^all))
			W(dp[i],1ll*dp[i|z[j]]*A[st[0]-w[i]-1][w[i|z[j]]-w[i]-1]%MOD);
	}ans=1ll*ans*dp[0]%MOD;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<=n;++i) for(int j=0;j<=i;++j)
	{
		C[i][j]=j?add(C[i-1][j],C[i-1][j-1]):1;
		A[i][j]=j?1ll*A[i-1][j-1]*i%MOD:1;
	}for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
	{
		tg[i]=1;
		for(int j=1;j<=n;++j) if(i!=j && !(a[i]%a[j]))
			tg[i]=0,e[i].pb(j),e[j].pb(i);
	}for(int i=1;i<=n;++i) if(!vs[i]) st[0]=st1[0]=0,dfs(i),slv();
	printf("%d\n",ans);return 0;
}