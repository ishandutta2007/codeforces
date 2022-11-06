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

const int MAXN=200005;

set<ll> g[MAXN];

ll vis[MAXN],pa[MAXN],d[MAXN];

void dfs(ll v){
	vis[v]=1;
	for(auto i:g[v]){
		if(!vis[i]){
			pa[i]=v;
			d[i]=d[v]+1;
			dfs(i);
		}
	}
}

#define oper max
pair<ll,ll> NEUT={-1,-1};
struct STree{
	vector<pair<ll,ll>> t; int n;
	STree(int n):t(2*n+5,NEUT),n(n){}
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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)g[i].clear();
		fore(i,0,n-1){
			ll x,y; cin>>x>>y; x--; y--;
			g[x].insert(y);
			g[y].insert(x);
		}
		fore(i,0,n){
			vis[i]=0;
			pa[i]=-1;
			d[i]=0;
		}
		dfs(0);
		fore(i,0,n)st.upd(i,{d[i],i});
		ll res=1;
		while(1){
			auto q=st.query(0,n);
			if(q==NEUT||q.snd==0)break;
			ll p=pa[q.snd];
			res+=SZ(g[p])-(p!=0)-1;
			for(auto i:g[p]){
				if(i!=pa[p])st.upd(i,NEUT);
			}
			st.upd(p,NEUT);
			if(pa[p]!=-1){
				g[pa[p]].erase(p);
			}
		}
		cout<<res<<"\n";
	}

	
	return 0;
}