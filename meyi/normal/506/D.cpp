#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10,maxp=666;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
typedef pair<int,int> pii;
#define fi first
#define se second
const int hmod=1e6+7;
int null;
template<class T1,class T2>
struct hmap{
	struct data{
		T1 id;
		T2 val;
		int nxt;
	}d[maxn<<1];
	int hd[hmod],len;
	void insert(T1 p,T2 &v){
		ri tmp=(114514ll*p.fi+1919810ll*p.se)%hmod;
		for(ri i=hd[tmp];i;i=d[i].nxt)
			if(d[i].id==p)
				return;
		d[++len]={p,++v,hd[tmp]};
		hd[tmp]=len;
	}
	inline T2& operator[](T1 p){
		ri tmp=(114514ll*p.fi+1919810ll*p.se)%hmod;
		for(ri i=hd[tmp];i;i=d[i].nxt)
			if(d[i].id==p)
				return d[i].val;
		return null;
	}
};
hmap<pii,int>id;
map<pii,int>ans;
struct node{
	int cnt;
	vector<int>fa;
	inline void insert(int p,int idx){
		id.insert(pii{p,idx},cnt);
	}
	inline void init(){
		fa.resize(cnt+1);
		for(ri i=1;i<=cnt;++i)fa[i]=i;
	}
	int find(int k){
		return k==fa[k]?k:fa[k]=find(fa[k]);
	}
	inline void merge(int x,int y,int idx){
		x=id[pii{x,idx}],y=id[pii{y,idx}];
		if(!x||!y)return;
		x=find(x),y=find(y);
		if(x!=y)fa[x]=y;
	}
	inline bool connect(int x,int y,int idx){
		x=id[pii{x,idx}],y=id[pii{y,idx}];
		if(!x||!y)return false;
		return find(x)==find(y);
	}
}a[maxn];
int deg[maxn],lim,m,n,q,x[maxn],y[maxn],z[maxn];
vector<int>bel[maxn];
signed main(){
	scanf("%d%d",&n,&m);
	lim=sqrt(m);
	for(ri i=1;i<=m;++i){
		scanf("%d%d%d",x+i,y+i,z+i);
		a[z[i]].insert(x[i],z[i]),a[z[i]].insert(y[i],z[i]);
		bel[x[i]].push_back(z[i]),bel[y[i]].push_back(z[i]);
	}
	for(ri i=1;i<=m;++i)a[i].init();
	for(ri i=1;i<=m;++i)a[z[i]].merge(x[i],y[i],z[i]);
	for(ri i=1;i<=n;++i){
		sort(bel[i].begin(),bel[i].end());
		bel[i].erase(unique(bel[i].begin(),bel[i].end()),bel[i].end());
		deg[i]=bel[i].size();
	}
	scanf("%d",&q);
	while(q--){
		ri u,v;
		scanf("%d%d",&u,&v);
		if(deg[u]>deg[v])swap(u,v);
		if(ans.count(pii{u,v}))printf("%d\n",ans[pii{u,v}]);
		else{
			ri sum=0;
			for(auto i:bel[u])sum+=a[i].connect(u,v,i);
			printf("%d\n",ans[pii{u,v}]=sum);
		}
	}
	return 0;
}