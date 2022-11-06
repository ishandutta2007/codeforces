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

ll MOD=998244353;

/*----------------CLASSIC SEGMENT TREE----------------*/
#define oper min
const ll NEUT=9e18;
struct STree { // [cerrado-abierto)
    vector<ll> st;int n;
    STree(int n): st(4*n+5,NEUT), n(n) {}
    void upd(int k, int s, int e, int p, ll v){
        if(s+1==e){st[k]=v;return;}
        int m=(s+e)/2;
        if(p<m)upd(2*k,s,m,p,v);
        else upd(2*k+1,m,e,p,v);
        st[k]=oper(st[2*k],st[2*k+1]);
    }
    ll query(int k, int s, int e, int a, int b){
        if(s>=b||e<=a)return NEUT;
        if(s>=a&&e<=b)return st[k];
        int m=(s+e)/2;
        return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
    }
    void upd(int p, ll v){upd(1,0,n,p,v);}
    ll query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree st(n);st.upd(i,v);st.query(s,e);

vector<ll> g[400005];

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll a[n],b[m];
	fore(i,0,n)cin>>a[i];
	fore(i,0,m)cin>>b[i];
	set<ll> st;
	fore(i,0,n)st.insert(a[i]);
	fore(i,0,m)st.insert(b[i]);
	map<ll,ll> mp;
	ll va=0;
	for(auto i:st)mp[i]=va++;
	fore(i,0,n)a[i]=mp[a[i]];
	fore(i,0,m)b[i]=mp[b[i]];
	fore(i,0,n){
		g[a[i]].pb(i);
	}
	fore(i,0,m){
		if(SZ(g[b[i]])==0){
			cout<<0;
			return 0;
		}
	}
	STree s(n);
	fore(i,0,n)s.upd(i,a[i]);
	fore(i,0,m){
		if(s.query(g[b[i]].back(),n)<b[i]){
			cout<<0;
			return 0;
		}
	}
	fore(i,0,g[b[0]].back()){
		if(a[i]<b[0]){
			cout<<0;
			return 0;
		}
	}
	ll res=1;
	fore(i,1,m){
		ll d=g[b[i]].back()-g[b[i-1]].back();
		fore(j,0,d){
			if(a[g[b[i]].back()-j]<b[i]){
				res=res*j%MOD; break;
			}
			if(j==d-1){
				res=res*d%MOD;
			}
		}
	}
	cout<<res;
	
	return 0;
}