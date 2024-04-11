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

const int MAXN=400005;

set<ll> g[MAXN];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		fore(i,0,n)g[i].clear();
		fore(i,0,n-1){
			ll x,y; cin>>x>>y; x--; y--;
			g[x].insert(y);
			g[y].insert(x);
		}
		vector<ll> vl;
		set<ll> vis;
		fore(i,0,n){
			if(SZ(g[i])<=1)vl.pb(i),vis.insert(i);
		}
		ll res=n;
		fore(_,0,k){
			set<ll> st;
			for(auto i:vl){
				for(auto j:g[i]){
					g[j].erase(i);
					if(SZ(g[j])<=1)st.insert(j);
				}
				g[i].clear();
			}
			res-=SZ(vl);
			vl.clear();
			for(auto i:st){
				if(!vis.count(i))vl.pb(i),vis.insert(i);
			}
			if(res==0)break;
		}
		cout<<res<<"\n";
	}
	
	return 0;
}