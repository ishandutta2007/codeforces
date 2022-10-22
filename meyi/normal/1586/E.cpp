#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=5e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
struct dsu{
	int fa[maxn],siz[maxn];
	inline void init(int k){for(ri i=1;i<=k;++i)fa[i]=i,siz[i]=1;}
	int find(int k){return k==fa[k]?k:fa[k]=find(fa[k]);}
	inline void merge(int x,int y){
		x=find(x),y=find(y);
		if(x!=y){
			if(siz[x]>siz[y])swap(x,y);
			fa[x]=y,siz[y]+=siz[x];
		}
	}
}d;
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
namespace LCA{
	int cnt,dep[maxn],fa[maxn],fir[maxn],lg,lg2[maxn<<1],st[(int)log2(maxn)+2][maxn<<1];
	void dfs(int p,int f){
		dep[p]=dep[f]+1;
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
using LCA::lca;
vector<int>ans[maxn],g[maxn];
int cnt,m,n,q,sum[maxn];
void dfs(int p){
	for(auto i:g[p])
		if(d.find(p)!=d.find(i)){
			addedge(p,i),addedge(i,p);
			d.merge(p,i);
			dfs(i);
		}
}
int main(){
	scanf("%d%d",&n,&m);
	d.init(n);
	while(m--){
		ri x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y),g[y].push_back(x);
	}
	dfs(1);
	LCA::init(1);
	scanf("%d",&q);
	for(ri i=1;i<=q;++i){
		ri x,y,z;
		scanf("%d%d",&x,&y);
		z=lca(x,y);
		vector<int>a,b;
		while(x!=z)a.push_back(x),++sum[x],x=LCA::fa[x];
		a.push_back(z);
		while(y!=z)b.push_back(y),++sum[y],y=LCA::fa[y];
		reverse(b.begin(),b.end());
		for(auto j:a)ans[i].push_back(j);
		for(auto j:b)ans[i].push_back(j);
	}
	for(ri i=1;i<=n;++i){
		ri tmp=(sum[i]&1);
		for(ri j=hd[i];j;j=e[j].nxt)
			if(e[j].to!=LCA::fa[i])
				tmp+=(sum[e[j].to]&1);
		cnt+=(tmp&1);
	}
	if(cnt)printf("NO\n%d",cnt>>1);
	else{
		puts("YES");
		for(ri i=1;i<=q;++i){
			printf("%u\n",ans[i].size());
			for(auto j:ans[i])printf("%d ",j);
			printf("\n");
		}
	}
	return 0;
}