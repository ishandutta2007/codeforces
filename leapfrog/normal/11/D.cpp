#include<bits/stdc++.h>
using namespace std;
struct edge{int to,nxt;}e[205];
int n,m,tot=0,head[25];long long dp[1048585][25],ans=0;
inline void adde(int x,int y) {e[++tot]=(edge){y,head[x]},head[x]=tot;}
inline long long dfs(int x,int rt,int s,int cnt)
{
	if(dp[s][x]) return dp[s][x];
	for(int i=head[x];i;i=e[i].nxt)
		if(s&(1<<(e[i].to-1))) {if(cnt>2&&rt==e[i].to) dp[s][x]++;}
		else if(e[i].to>rt) dp[s][x]+=dfs(e[i].to,rt,s|(1<<(e[i].to-1)),cnt+1);
	return dp[s][x];
}
int main()
{
	scanf("%d%d",&n,&m),memset(head,0,sizeof(head)),memset(dp,0,sizeof(dp));
	for(int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y),adde(x,y),adde(y,x);
	for(int i=1;i<=n;i++) ans+=dfs(i,i,(1<<(i-1)),1);
	return printf("%lld\n",ans/2),0;
}