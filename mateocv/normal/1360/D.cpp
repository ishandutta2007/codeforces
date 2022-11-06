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
			if(i!=n/i)res.pb(n/i);
		}
	}
	//sort(ALL(res));
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n, k; cin>>n>>k;
		auto d=div(n);
		ll res=1;
		for(auto i:d){
			if(i<=k)res=max(res,i);
		}
		cout<<n/res<<"\n";
	}
	
	return 0;
}