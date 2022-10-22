#include<bits/stdc++.h>
#define N 300010
using namespace std;
int fir[N],nxt[N<<1],to[N<<1],cnt;
void add(int u,int v){nxt[++cnt]=fir[u];fir[u]=cnt;to[cnt]=v;}
int f[N],g[N],a[N];
void dfs(int x,int fa)
{
	if (!fir[x]) {f[x]=g[x]=1;return;}
	if (a[x]) f[x]=1e9;
	for (int i=fir[x];i;i=nxt[i]) if (to[i]!=fa)
	{
		dfs(to[i],x);g[x]+=g[to[i]];
		if (a[x]) f[x]=min(f[x],g[to[i]]-f[to[i]]);
		else f[x]+=g[to[i]]-f[to[i]]+1;
	}
	f[x]=g[x]-f[x];f[x]+=1-a[x];
}
int main()
{
	int n,t,i;cin>>n;
	for (i=1;i<=n;i++) cin>>a[i];
	for (i=2;i<=n;i++) cin>>t,add(t,i);
	dfs(1,0);cout<<f[1];
}