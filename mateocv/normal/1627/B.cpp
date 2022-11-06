#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll> res;
		fore(i,0,n){
			fore(j,0,m){
				res.pb(max(i,n-1-i)+max(j,m-1-j));
			}
		}
		sort(ALL(res));
		//reverse(ALL(res));
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}
	
	return 0;
}