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

vector<pair<ll,ll>> g[300005];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll u,v;
		fore(i,0,m){
			cin>>u>>v; u--; v--;
			g[u].pb({v,i});
			g[v].pb({u,i});
		}
		set<ll> st;
		vector<ll> mat;
		fore(i,0,3*n){
			st.insert(i);
			for(auto j:g[i]){
				if(st.count(j.fst)){
					st.erase(i);
					st.erase(j.fst);
					mat.pb(j.snd);
					break;
				}
			}
			if(SZ(st)==n||SZ(mat)==n)break;
		}
		if(SZ(st)==n){
			cout<<"IndSet\n";
			for(auto i:st)cout<<i+1<<" "; cout<<"\n";
		}else if(SZ(mat)==n){
			cout<<"Matching\n";
			for(auto i:mat)cout<<i+1<<" "; cout<<"\n";
		}
		fore(i,0,3*n){
			g[i].clear();
		}
	}
	
	return 0;
}