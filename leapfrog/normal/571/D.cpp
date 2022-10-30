//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
const int N=500005;int n,m,cl[N];
struct node{ll sm;int ti;char operator<(node b) const {return ti<b.ti;}};
struct DSU
{
	int fa[N],sz[N],tim[N];
	inline void init() {for(int i=0;i<N;i++) fa[i]=i,sz[i]=1,tim[i]=0;}
	inline int getf(int x) {return fa[x]==x?x:getf(fa[x]);}
	inline void merge(int x,int y,int tm)
	{
		x=getf(x),y=getf(y);if(x==y) return;else if(sz[x]<sz[y]) swap(x,y);
		fa[y]=x,sz[x]+=sz[y],tim[y]=tm;
	}
}G1,G2;vector<node>ad[N];
int main()
{
	read(n),read(m),G1.init(),G2.init();char ch;
	for(int i=1;i<=n;i++) ad[i].push_back((node){0,-1});
	for(int i=1,x,y;i<=m;i++)
	{
		scanf("%s",&ch),read(x);
		if(ch=='U') {read(y),G1.merge(x,y,i);continue;}
		if(ch=='M') {read(y),G2.merge(x,y,i);continue;}
		if(ch=='A') {x=G1.getf(x),ad[x].push_back((node){ad[x].back().sm+G1.sz[x],i});continue;}
		if(ch=='Z') {x=G2.getf(x),cl[x]=i;continue;}
		int u=x,clr=cl[u];ll res=0;for(;G2.fa[u]^u;u=G2.fa[u])
			if(cl[G2.fa[u]]>G2.tim[u]) clr=max(clr,cl[G2.fa[u]]);
		u=x;int l=lower_bound(ad[u].begin(),ad[u].end(),(node){114,clr})-ad[u].begin();
		res+=ad[u].back().sm-ad[u][l-1].sm;for(;G1.fa[u]^u;u=G1.fa[u])
		{
			int F=G1.fa[u];l=lower_bound(ad[F].begin(),ad[F].end(),(node){514,max(clr,G1.tim[u])})-ad[F].begin();
			res+=ad[F].back().sm-ad[F][l-1].sm;
		}
		printf("%lld\n",res);
	}
	return 0;
}