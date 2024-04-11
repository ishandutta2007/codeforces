#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
struct edge{
	int v,to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to,int v=1){
	e[++len]={v,to,hd[fr]};
	hd[fr]=len;
}
namespace LCA{
	int cnt,dep[maxn],fir[maxn],lg,lg2[maxn<<1],st[(int)log2(maxn)+2][maxn<<1];
	ll dis[maxn];
	void dfs(int p,int f){
		dep[p]=dep[f]+1;
		st[0][++cnt]=p;
		fir[p]=cnt;
		for(ri i=hd[p];i;i=e[i].nxt)
			if(e[i].to!=f)
				dis[e[i].to]=dis[p]+e[i].v,dfs(e[i].to,p),st[0][++cnt]=p;
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
	inline ll dist(int x,int y){
		return dis[x]+dis[y]-(dis[lca(x,y)]<<1);
	}
	inline void init(int rt){
		cnt=0;
		dfs(rt,0);
		build_st();
	}
}
using LCA::lca;
using LCA::dist;
int a,ans,b,da,db,m,mx[maxn],n,t_case;
void dfs(int p,int f){
	mx[p]=0;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f){
			dfs(e[i].to,p);
			ckmax(ans,mx[p]+mx[e[i].to]+1);
			ckmax(mx[p],mx[e[i].to]+1);
		}
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
		clear(hd,n),len=0;
		for(ri i=1,x,y;i<n;++i){
			scanf("%d%d",&x,&y);
			addedge(x,y),addedge(y,x);
		}
		if(db<=2*da){
			puts("Alice");
			continue;
		}
		LCA::init(1);
		if(dist(a,b)<=da){
			puts("Alice");
			continue;
		}
		ans=0;
		dfs(1,0);
		if(ans<=2*da){
			puts("Alice");
			continue;
		}
		puts("Bob");
	}
	return 0;
}