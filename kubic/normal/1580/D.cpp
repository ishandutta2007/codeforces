#include <bits/stdc++.h>
using namespace std;
#define N 4005
#define ll long long
int n,m,rt,a[N],st[N],sz[N],ch[N][2];ll dp[N][N];
void dfs(int u)
{
	if(!u) return;dfs(ch[u][0]);dfs(ch[u][1]);sz[u]=sz[ch[u][0]]+sz[ch[u][1]]+1;
	for(int i=0;i<=sz[ch[u][0]];++i) for(int j=0;j<=sz[ch[u][1]];++j)
		dp[u][i+j]=max(dp[u][i+j],dp[ch[u][0]][i]+dp[ch[u][1]][j]-2ll*i*j*a[u]);
	for(int i=sz[u]-1;i>=0;--i) dp[u][i+1]=max(dp[u][i+1],dp[u][i]+1ll*(m-i*2-1)*a[u]);
}
int main()
{
	scanf("%d %d",&n,&m);for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
	{
		while(st[0] && a[i]<a[st[st[0]]]) ch[i][0]=st[st[0]--];
		ch[st[st[0]]][1]=i;st[++st[0]]=i;
	}dfs(st[1]);printf("%lld\n",dp[st[1]][m]);return 0;
}