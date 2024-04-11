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

vector<ll> g[200005];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		fore(i,0,n)cin>>a[i],a[i]--;
		fore(i,0,n){
			g[i].clear();
			g[i].pb(0);
		}
		fore(i,0,n){
			g[a[i]].pb(i+1);
		}
		fore(i,0,n){
			g[i].pb(n+1);
		}
		ll res=n;
		fore(i,0,n){
			if(SZ(g[i])==2)continue;
			ll va=0;
			fore(j,0,SZ(g[i])-1){
				va+=(g[i][j+1]>g[i][j]+1);
			}
			res=min(res,va);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}