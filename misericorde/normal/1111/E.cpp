#include <bits/stdc++.h>
#define maxn 100005
#define ll long long
const int ouuan=1e9+7;
//test
int n,q,k,m,r,f[maxn],arr[maxn],dp[maxn][302],head[maxn]={0},tail=0,depth[maxn]={0},size[maxn]={0},sum[maxn]={0},son[maxn]={0},
ref[maxn],top[maxn],fa[maxn],dfn=0;
struct edge {
	int v,next;
}edges[maxn<<1];
void add_edge(int u,int v) {
	edges[++tail].v=v;
	edges[tail].next=head[u];
	head[u]=tail;
}

void add(int p,int v) {
	while (p<=n) {sum[p]+=v;p+=p&-p;}
} int query(int p) {
	int ans=0;
	while (p) {ans+=sum[p];p-=p&-p;}
	return ans;
}

void dfs1(int u,int f) {
	fa[u]=f;depth[u]=depth[f]+1;size[u]=1;
	for (int i=head[u];i;i=edges[i].next) {
		int v=edges[i].v;
		if (v==f) continue;
		dfs1(v,u); size[u]+=size[v];
		if (size[v]>size[son[u]]) son[u]=v;
	}
}

void dfs2(int u,int tp) {
	top[u]=tp;ref[u]=++dfn;
	if (son[u]) dfs2(son[u],tp);
	for (int i=head[u];i;i=edges[i].next) {
		int v=edges[i].v;
		if (v==son[u]||v==fa[u]) continue;
		dfs2(v,v);
	}
}

int TreeQuery(int u,int v) {
	int ans=0;
	while (top[u]!=top[v]) {
		if (depth[top[u]]<depth[top[v]]) std::swap(u,v);
		ans+=query(ref[u])-query(ref[top[u]]-1);
		u=fa[top[u]];
	}if (depth[u]<depth[v])std::swap(u,v);
	return ans+query(ref[u])-query(ref[v]-1);
}

int cmp(int a,int b) {return a<b;}

int main() {
	//freopen("sample.txt","r",stdin);
	scanf("%d%d",&n,&q);
	for (int i=1;i<n;++i) {
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);add_edge(v,u);
	} dfs1(1,0);dfs2(1,1);
//	for (int i=1;i<=n;++i) printf("%d ",ref[i]);printf("\n");
	while (q--) {
		scanf("%d%d%d",&k,&m,&r);
		for (int i=1;i<=k;++i) {
			scanf("%d",&arr[i]);
			add(ref[arr[i]],1);
		} for (int i=1;i<=k;++i) 
			f[i]=TreeQuery(arr[i],r);
		
		std::sort(f+1,f+k+1,cmp);//for (int i=1;i<=k;++i) printf("%d ",f[i]); printf("\n");
		dp[0][0]=1;
		for (int i=1;i<=k;++i) 
			for (int j=1;j<=std::min(m,i);++j)
				dp[i][j]=((ll)dp[i-1][j]*(ll)std::max(0,j-f[i]+1)%ouuan+dp[i-1][j-1])%ouuan;
		
		int ans=0;
		for (int i=1;i<=m;++i) ans=(ans+dp[k][i])%ouuan;
		printf("%d\n",ans);
		for (int i=1;i<=k;++i) 
			for (int j=1;j<=std::min(m,i);++j)
				dp[i][j]=0;
		for (int i=1;i<=k;++i) add(ref[arr[i]],-1);
	}
	return 0;
}