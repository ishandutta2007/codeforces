#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
namespace LCA{
	int cnt,dep[maxn],fir[maxn],lg,lg2[maxn<<1],st[(int)log2(maxn)+2][maxn<<1];
	void dfs(int p,int f){
		dep[p]=dep[f]+1;
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
	inline int dist(int x,int y){
		return dep[x]+dep[y]-(dep[lca(x,y)]<<1);
	}
	inline void init(int rt){
		dfs(rt,0);
		build_st();
	}
}
using LCA::lca;
using LCA::dist;
bool vis[maxn];
int mx[maxn],rt,siz[maxn],tot;
void calc_siz(int p,int f){
	mx[p]=0;
	siz[p]=1;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(!vis[e[i].to]&&e[i].to!=f){
			calc_siz(e[i].to,p);
			ckmax(mx[p],siz[e[i].to]);
			siz[p]+=siz[e[i].to];
		}
	ckmax(mx[p],tot-siz[p]);
	if(mx[p]<mx[rt])rt=p;
}
int fa[maxn];
vector<int>sum[maxn][2];
void dfs(int p){
	vis[p]=true;
	siz[p]=tot+1;
	sum[p][0].resize(siz[p]+1);
	sum[p][1].resize(siz[p]+1);
	for(ri i=hd[p];i;i=e[i].nxt)
		if(!vis[e[i].to]){
			rt=0,tot=siz[e[i].to];
			calc_siz(e[i].to,0);
			fa[rt]=p;
			dfs(rt);
		}
}
#define lowbit(k) (k&-k)
inline void add(int p,int id,int k,int v){
	for(ri i=k+1;i<=siz[p];i+=lowbit(i))sum[p][id][i]+=v;
}
inline int query(int p,int id,int k){
	ri ret=0;
	for(ri i=min(k+1,siz[p]);i;i^=lowbit(i))ret+=sum[p][id][i];
	return ret;
}
inline void modify(int p){
	for(ri i=p;i;i=fa[i])add(i,0,dist(p,i),1);
	for(ri i=p;fa[i];i=fa[i])add(i,1,dist(p,fa[i]),1);
}
int a[maxn],ans,k,m,n;
signed main(){
	scanf("%d%d%d",&n,&m,&k);
	for(ri i=1;i<=m;++i)scanf("%d",a+i);
	for(ri i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		addedge(x,y),addedge(y,x);
	}
	LCA::init(1);
	mx[0]=INT_MAX,tot=n;
	calc_siz(1,0);
	dfs(rt);
	for(ri i=1;i<=m;++i)modify(a[i]);
	for(ri i=1;i<=n;++i){
		ri tmp=query(i,0,k);
		for(ri j=i;fa[j];j=fa[j]){
			ri d=dist(i,fa[j]);
			if(d<=k)tmp+=query(fa[j],0,k-d)-query(j,1,k-d);
		}
		if(tmp==m)++ans;
	}
	printf("%d",ans);
	return 0;
}