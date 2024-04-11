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

vector<ll> div(ll n){
	vector<ll> res;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
			res.pb(i);
			if(n/i!=i)res.pb(n/i);
		}
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll l,w; cin>>l>>w;
		set<ll> res={1};
		vector<vector<ll>> v={{w-2,l},{l-2,w},{w-1,l-1},{w-2,w,l-1},{l-2,l,w-1}};
		for(auto i:v){
			ll g=0;
			for(auto j:i)g=__gcd(g,j);
			auto d=div(g);
			for(auto j:d)res.insert(j);
		}
		cout<<SZ(res)<<" ";
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}
	
	return 0;
}