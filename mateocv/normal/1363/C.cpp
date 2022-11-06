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

vector<ll> g[1010];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,x; cin>>n>>x;
		x--;
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--; v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		if(SZ(g[x])<=1){
			cout<<"Ayush\n";
		}else{
			if(n%2==0){
				cout<<"Ayush\n";
			}else{
				cout<<"Ashish\n";
			}
		}
		fore(i,0,n)g[i].clear();
		
	}
	
	return 0;
}