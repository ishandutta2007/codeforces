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
		ll n; cin>>n;
		vector<ll> v[2];
		fore(i,0,n){
			ll x; cin>>x;
			v[x&1].pb(x);
		}
		for(auto i:v[0])cout<<i<<" ";
		for(auto i:v[1])cout<<i<<" ";
		cout<<"\n";
	}
	
	return 0;
}