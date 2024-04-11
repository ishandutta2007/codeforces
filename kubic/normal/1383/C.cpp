#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define M 25
#define C 1<<20
#define clz __builtin_clz
const int INF=1e9;
int T,n,tp,ans,st[M],dp[C];char a[N],b[N];bool vs[M],z[C][M],e[M][M];
void W(int &x,int y) {x=min(x,y);}
void dfs(int u)
{
	if(vs[u]) return;vs[u]=1;st[tp++]=u;
	for(int i=0;i<20;++i) if(e[u][i] || e[i][u]) dfs(i);
}
void slv()
{
	scanf("%d %s %s",&n,a+1,b+1);ans=0;for(int i=0;i<20;++i) vs[i]=0;
	for(int i=0;i<20;++i) for(int j=0;j<20;++j) e[i][j]=0;
	for(int i=1;i<=n;++i) e[a[i]-'a'][b[i]-'a']=1;
	for(int i=0,t;i<20;++i) if(!vs[i])
	{
		tp=0;dfs(i);
		for(int j=1;j<1<<tp;++j) for(int k=0;k<tp;++k)
			t=31-clz(j&-j),z[j][k]=z[j^(1<<t)][k]|e[st[k]][st[t]];
		for(int j=1;j<1<<tp;++j)
		{
			dp[j]=INF;
			for(int k=0;k<tp;++k) if(j>>k&1)
				W(dp[j],dp[j^(1<<k)]+(j!=1<<k)+z[j^(1<<k)][k]);
		}ans+=dp[(1<<tp)-1];
	}printf("%d\n",ans);
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}