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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,h,m; cin>>n>>h>>m;
		ll l=60ll*h+m,mod=60ll*24;
		ll mini=mod;
		fore(i,0,n){
			ll x,y; cin>>x>>y;
			mini=min(mini,(60ll*x+y-l+mod)%mod);
		}
		cout<<mini/60<<" "<<mini%60<<"\n";
	}
	
	return 0;
}