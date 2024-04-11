#include<bits/stdc++.h>
using namespace std;
struct edge{int to,nxt;}e[200005<<1];
int n,k,q,c,tot=0,cnt=0,head[200005],dep[200005],f[200005],dfn[200005],siz[200005],t[200005];
inline void adde(int x,int y) {e[++tot]=(edge){y,head[x]},head[x]=tot;}
inline void dfs(int x,int fa=1)
{
	f[x]=fa,dep[x]=dep[fa]+1,dfn[x]=++cnt,siz[x]=1;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs(e[i].to,x),siz[x]+=siz[e[i].to];
}
inline char in(int x,int y) {return dfn[x]<=dfn[y]&&dfn[y]<=dfn[x]+siz[x]-1;}
inline bool cmp(int x,int y) {return dep[x]<dep[y];}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),adde(x,y),adde(y,x);
	for(c=0,dep[1]=1,dfs(1);q--;c=0)
	{
		scanf("%d",&k);
		for(int i=1;i<=k;i++) scanf("%d",&t[i]),t[i]=f[t[i]];
		sort(t+1,t+k+1,cmp);
		for(int i=1;i<k;i++) if(!in(t[i],t[i+1])) c=1;
		if(c) puts("NO");else puts("YES");
	}
	return 0;
}