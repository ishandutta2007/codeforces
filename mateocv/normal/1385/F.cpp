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
vector<ll> h[MAXN];

/*----------------CLASSIC SEGMENT TREE----------------*/
#define oper max
const pair<ll,ll> NEUT={0,-1};
struct STree { // [cerrado-abierto)
    vector<pair<ll,ll>> st;int n;
    STree(int n): st(4*n+5,NEUT), n(n) {}
    void upd(int k, int s, int e, int p, pair<ll,ll> v){
        if(s+1==e){st[k]=v;return;}
        int m=(s+e)/2;
        if(p<m)upd(2*k,s,m,p,v);
        else upd(2*k+1,m,e,p,v);
        st[k]=oper(st[2*k],st[2*k+1]);
    }
    pair<ll,ll> query(int k, int s, int e, int a, int b){
        if(s>=b||e<=a)return NEUT;
        if(s>=a&&e<=b)return st[k];
        int m=(s+e)/2;
        return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
    }
    void upd(int p, pair<ll,ll> v){upd(1,0,n,p,v);}
    pair<ll,ll> query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree st(n);st.upd(i,v);st.query(s,e);

STree st(MAXN);

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--; v--;
			g[u].insert(v);
			g[v].insert(u);
		}
		fore(i,0,n){
			for(auto j:g[i]){
				if(SZ(g[j])==1){
					h[i].pb(j);	
				}
			}
			st.upd(i,{SZ(h[i]),i});
		}
		ll res=0;
		while(1){
			auto q=st.query(0,n);
			assert(q.snd!=-1);
			if(q.fst>=k){
				res++;
				fore(j,0,k){
					g[q.snd].erase(h[q.snd].back());
					g[h[q.snd].back()].erase(q.snd);
					h[h[q.snd].back()].clear();
					st.upd(h[q.snd].back(),{0,h[q.snd].back()});
					h[q.snd].pop_back();
				}
				st.upd(q.snd,{SZ(h[q.snd]),q.snd});
				if(SZ(g[q.snd])==1){
					for(auto j:g[q.snd]){
						h[j].pb(q.snd);
						st.upd(j,{SZ(h[j]),j});
					}
				}
			}else{
				break;
			}
		}
		cout<<res<<"\n";
		fore(i,0,n)g[i].clear(),h[i].clear();
	}
	
	return 0;
}