//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct EDGE
{
	int et,head[100005];struct edge{int to,nxt;}e[200005];
	inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
}e1,e2;int n,dep[100005],dt,dfn[100005],fa[100005][25],Q;
int tp,st[100005],dp[100005],sz[100005],a[100005];char tag[100005];
#define GO(a,x) for(int i=a.head[x],v=a.e[i].to;i;i=a.e[i].nxt,v=a.e[i].to)
inline void dfs0(int x,int pa)
{
	dep[x]=dep[pa]+1,fa[x][0]=pa,dfn[x]=++dt;
	for(int i=1;i<20;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	GO(e1,x) if(v!=pa) dfs0(v,x);
}
inline void dfs1(int x,int fa)
{
	sz[x]=dp[x]=0;GO(e2,x) if(v!=fa) dfs1(v,x),sz[x]+=sz[v],dp[x]+=dp[v];
	e2.head[x]=0;if(tag[x]) dp[x]+=sz[x],sz[x]=1,tag[x]=0,tag[x]=0;else if(sz[x]>1) dp[x]++,sz[x]=0;
}
inline int LCA(int a,int b)
{
	if(dep[a]<dep[b]) swap(a,b);
	for(int i=19;~i;i--) if(dep[fa[a][i]]>=dep[b]) a=fa[a][i];
	if(a==b) return a;
	for(int i=19;~i;i--) if(fa[a][i]!=fa[b][i]) a=fa[a][i],b=fa[b][i];
	return fa[a][0];
}
inline char cmp(int a,int b) {return dfn[a]<dfn[b];}
int main()
{
	read(n);for(int i=1,x,y;i<n;i++) read(x),read(y),e1.adde(x,y),e1.adde(y,x);
	for(read(Q),dfs0(1,0);Q--;)
	{
		int k;read(k),e2.et=0;char flg=0;tp=0;
		for(int i=1;i<=k;i++) read(a[i]),tag[a[i]]=1;
		for(int i=1;i<=k;i++) if(a[i]!=1&&tag[fa[a[i]][0]]) flg=1;
		if(flg) {for(int i=1;i<=k;i++) tag[a[i]]=0;puts("-1");continue;}else sort(a+1,a+k+1,cmp),st[++tp]=1;
		for(int i=1;i<=k;i++)
		{
			int x=a[i],lc=LCA(a[i],st[tp]);
			while(st[tp]!=lc) {int v=st[tp--];if(dfn[st[tp]]<dfn[lc]) st[++tp]=lc;e2.adde(st[tp],v);}
			st[++tp]=x;
		}
		while(st[tp]!=1) {int x=st[tp--];e2.adde(st[tp],x);}
		dfs1(1,0),printf("%d\n",dp[1]);
	}
	return 0;
}