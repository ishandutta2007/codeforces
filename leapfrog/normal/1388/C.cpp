#include<bits/stdc++.h>
using namespace std;
struct edge{int to,nxt;}e[200005];
int t,n,m,head[100005],et,h[100005],p[100005],w[100005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline int dfs(int x,int fa=0)
{
	int zk=0;
	for(int i=head[x];i;i=e[i].nxt)
		if(e[i].to!=fa)
		{
			if(!dfs(e[i].to,x)) return 0;
			p[x]+=p[e[i].to],zk+=w[e[i].to];
		}
	if((p[x]+h[x])%2||h[x]>p[x]) return 0;
	w[x]=(p[x]+h[x])/2;
	if(w[x]<zk) return 0;
	return 1;
}
signed main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d%d",&n,&m),et=0,memset(head,0,sizeof(head));
		for(int i=1;i<=n;i++) scanf("%d",p+i);
		for(int i=1;i<=n;i++) scanf("%d",h+i);
		for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),adde(x,y),adde(y,x);
		if(dfs(1)) puts("YES");else puts("NO");
	}
	return 0;
}