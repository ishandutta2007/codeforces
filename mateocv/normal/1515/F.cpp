#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const int MAXN=300005;

ll xx;

ll a[MAXN];

vector<pair<ll,ll>> ed;

set<pair<ll,ll>> g[MAXN];

/*----------------SEGMENT_TREE_ITERATIVO----------------*/
#define oper max
#define NEUT {-1,-1}
struct STree{
	vector<pair<ll,ll>> t; int n;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, pair<ll,ll> value){
		for(t[p += n]=value;p>1;p>>=1) t[p>>1]=oper(t[p],t[p^1]);
	}
	pair<ll,ll> query(int l, int r){ // [l, r)
		pair<ll,ll> res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1) res=oper(res,t[l++]);
			if(r&1) res=oper(res,t[--r]);
		}
		return res;
	}
};

STree st(MAXN);

/*----------------DSU------------------*/
ll pa[MAXN],sz[MAXN],c[MAXN];
ll find_pa(ll pos){
	if(pa[pos]!=pos)pa[pos]=find_pa(pa[pos]);
	return pa[pos];
}
void join(int a, int b) {
	int x=find_pa(a),y=find_pa(b);
	if (x!=y) {
		if(sz[x]>=sz[y])swap(x,y);
		sz[y]+=sz[x],pa[x]=y,c[y]=c[y]+c[x]-xx;
		assert(c[y]>=0);
		st.upd(y,{c[y],y});
		st.upd(x,NEUT);
		for(auto i:g[x]){
			g[y].insert(i);
		}
		g[x].clear();
	}
}
void dsu_init(ll n){fore(i,0,n)pa[i]=i,sz[i]=1,c[i]=a[i];}

int main(){FIN;
	ll n,m; cin>>n>>m>>xx;
	fore(i,0,n)cin>>a[i];
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--; v--;
		ed.pb({u,v});
		g[u].insert({v,i});
		g[v].insert({u,i});
	}
	ll s=0;
	fore(i,0,n)s+=a[i];
	if(s<(n-1)*xx){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	dsu_init(n);
	fore(i,0,n)st.upd(i,{a[i],i});
	vector<ll> res;
	while(SZ(res)<n-1){
		auto q=st.query(0,n);
		if(q.fst>=xx){
			while(1){
				assert(SZ(g[q.snd]));
				auto b=*g[q.snd].begin();
				g[q.snd].erase(b);
				if(find_pa(b.fst)!=find_pa(q.snd)){
					res.pb(b.snd);
					join(b.fst,q.snd);
					break;
				}
			}
		}else{
			while(1){
				assert(SZ(ed));
				auto b=ed.back();
				ed.pop_back();
				if(find_pa(b.fst)!=find_pa(b.snd)){
					res.pb(SZ(ed));
					join(b.fst,b.snd);
					break;
				}
			}
		}
	}
	for(auto i:res)cout<<i+1<<"\n";
	
	return 0;
}