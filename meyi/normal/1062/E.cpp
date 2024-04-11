#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int cnt,dep[maxn],dfn[maxn],fir[maxn];
void dfs(int p,int f){
	dep[p]=dep[f]+1;
	dfn[++cnt]=p;
	fir[p]=cnt;
	for(ri i=hd[p];i;i=e[i].nxt){
		dfs(e[i].to,p);
		dfn[++cnt]=p;
	}
}
int lg2[maxn];
struct ST{
	int st[(int)log2(maxn)+1][maxn];
	template<class T>
	inline void build(int *arr,int siz,T min){
		if(!lg2[siz])
			for(ri i=2;i<=siz;++i)
				lg2[i]=lg2[i-1]+!(i&(i-1));
		for(ri i=1;i<=siz;++i)st[0][i]=arr[i];
		ri lg=lg2[siz];
		for(ri i=1;i<=lg;++i)
			for(ri j=1;j+(1<<i)-1<=siz;++j)
				st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	}
	template<class T>
	inline int query(int l,int r,T min){
		if(l>r)swap(l,r);
		ri k=lg2[r-l+1];
		return min(st[k][l],st[k][r-(1<<k)+1]);
	}
}x,y,z;
int m,n,pt[maxn];
signed main(){
	scanf("%d%d",&n,&m);
	for(ri i=2,x;i<=n;++i)scanf("%d",&x),addedge(x,i);
	dfs(1,0);
	auto dmin=[](const int &x,const int &y){return dep[x]<dep[y]?x:y;};
	x.build(dfn,cnt,dmin);
	for(ri i=1;i<=n;++i)pt[i]=i;
	auto fmin=[](const int &x,const int &y){return fir[x]<fir[y]?x:y;};
	y.build(pt,n,fmin);
	auto fmax=[](const int &x,const int &y){return fir[x]>fir[y]?x:y;};
	z.build(pt,n,fmax);
	while(m--){
		ri l,r;
		scanf("%d%d",&l,&r);
		auto lca=[&](const int &L,const int &R){return x.query(fir[y.query(L,R,fmin)],fir[z.query(L,R,fmax)],dmin);};
		ri mn=y.query(l,r,fmin),mx=z.query(l,r,fmax);
		auto del_lca=[&](const int &pos){
			if(pos==l)return lca(l+1,r);
			else if(pos==r)return lca(l,r-1);
			else return x.query(fir[lca(l,pos-1)],fir[lca(pos+1,r)],dmin);
		};
		ri mn_lca=del_lca(mn),mx_lca=del_lca(mx);
		if(dep[mn_lca]>dep[mx_lca])printf("%d %d\n",mn,dep[mn_lca]-1);
		else printf("%d %d\n",mx,dep[mx_lca]-1);
	}
	return 0;
}