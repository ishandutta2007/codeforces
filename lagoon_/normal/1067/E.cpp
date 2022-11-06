#include<bits/stdc++.h>
using namespace std;
#define re register
int g[500100][2],sz[500100],ex[500100],n;
struct edge{int to;edge*nx;}e[1000100],*la[500100],*cnt=e;
const int mod=998244353;
inline void addE(re int a,re int b)
{
	*++cnt=(edge){b,la[a]};la[a]=cnt;
	*++cnt=(edge){a,la[b]};la[b]=cnt;
}
int ans;
void dfs(re int a,re int fa)
{
	sz[a]=1;g[a][1]=1;
	for(re edge*i=la[a];i;i=i->nx)if(i->to!=fa)
	{
		dfs(i->to,a);
		sz[a]+=sz[i->to];ans=(ans+2ll*g[a][1]*g[i->to][1]%mod*ex[n-sz[a]])%mod;
		re int x=g[a][0],y=g[a][1];
		g[a][0]=(2ll*x*(g[i->to][0]+g[i->to][1])+(long long)y*g[i->to][1])%mod;
		g[a][1]=y*(2ll*g[i->to][0]+g[i->to][1])%mod;
	}
}
int main()
{
	re int x,y;
	scanf("%d",&n);ex[0]=1;
	for(re int i=1;i<n;i++)scanf("%d%d",&x,&y),addE(x,y),ex[i]=ex[i-1]*2%mod;
	dfs(1,0);
	printf("%d\n",ans);
}