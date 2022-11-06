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

vector<ll> g[100005];

ll a[100005];

vector<ll> val;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)g[i].clear();
		fore(i,0,n)cin>>a[i];
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--; v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		val.clear();
		fore(i,0,n){
			fore(j,0,SZ(g[i])-1)val.pb(a[i]);
		}
		sort(ALL(val));
		ll sum=0;
		fore(i,0,n)sum+=a[i];
		cout<<sum<<" ";
		fore(i,0,n-2){
			sum+=val.back();
			val.pop_back();
			cout<<sum<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}