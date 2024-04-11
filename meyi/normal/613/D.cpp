#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
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
int fa[maxn];
namespace LCA{
	int cnt,dep[maxn],dfn[maxn],fir[maxn],lg,lg2[maxn<<1],lst,st[(int)log2(maxn)+2][maxn<<1];
	void dfs(int p,int f){
		dep[p]=dep[f]+1;
		dfn[p]=++lst;
		fa[p]=f;
		st[0][++cnt]=p;
		fir[p]=cnt;
		for(ri i=hd[p];i;i=e[i].nxt)
			if(e[i].to!=f)
				dfs(e[i].to,p),st[0][++cnt]=p;
	}
	inline int ptmin(const int &x,const int &y){
		return dep[x]<dep[y]?x:y;
	}
	inline void build_st(){
		for(ri i=1;i<=cnt;++i)lg2[i]=lg2[i-1]+((2<<lg2[i-1])==i);
		lg=lg2[cnt];
		for(ri i=1;i<=lg;++i)
			for(ri j=1;j+(1<<i)-1<=cnt;++j)
				st[i][j]=ptmin(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	}
	inline int lca(int x,int y){
		ri l=fir[x],r=fir[y];
		if(l>r)swap(l,r);
		ri k=lg2[r-l+1];
		return ptmin(st[k][l],st[k][r-(1<<k)+1]);
	}
	inline void init(int rt){
		dfs(rt,0);
		build_st();
	}
}
using LCA::dep;
using LCA::dfn;
using LCA::lca;
int ans,siz[maxn],st[maxn],tp;
vector<int>g[maxn],sp;
#define link(x,y) g[x].push_back(y)
bool vis[maxn];
inline bool cmp(const int &x,const int &y){
	return dfn[x]<dfn[y];
}
inline void insert(int p){
	if(tp){
		ri anc=lca(p,st[tp]);
		while(tp>1&&dep[anc]<dep[st[tp-1]]){
			link(st[tp-1],st[tp]);
			--tp;
		}
		if(tp&&dep[anc]<dep[st[tp]])link(anc,st[tp]),--tp;
		if(!tp||anc!=st[tp])st[++tp]=anc;
	}
	st[++tp]=p;
}
bool flag;
inline void build_vt(){
	sort(sp.begin(),sp.end(),cmp);
	for(auto i:sp){
		if(vis[fa[i]])flag=true;
		insert(i),vis[i]=true;
	}
	while(--tp)link(st[tp],st[tp+1]);
}
void dfs(int p){
	if(flag)
		for(auto i:g[p])dfs(i);
	else{
		for(auto i:g[p]){
			dfs(i);
			if(siz[i]){
				if(vis[p])++ans;
				else siz[p]+=siz[i];
				siz[i]=0;
			}
		}
		if(vis[p])siz[p]=1;
		else if(siz[p]>1)++ans,siz[p]=0;
	}
	g[p].clear();
	vis[p]=false;
}
int m,n;
signed main(){
	scanf("%d",&n);
	for(ri i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		addedge(x,y),addedge(y,x);
	}
	LCA::init(1);
	scanf("%d",&m);
	while(m--){
		ri x,y;
		scanf("%d",&x);
		sp.clear();
		while(x--)scanf("%d",&y),sp.push_back(y);
		ans=flag=0;
		build_vt();
		if(flag)ans=-1;
		dfs(st[1]);
		siz[st[1]]=0;
		printf("%d\n",ans);
	}
	return 0;
}