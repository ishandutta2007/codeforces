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

vector<ll> di(ll n){
	vector<ll> res;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
			res.pb(i);
			if(i*i!=n)res.pb(n/i);
		}
	}
	return res;
}

vector<ll> comb(vector<ll> a, vector<ll> b){
	vector<ll> res;
	for(auto i:a){
		for(auto j:b){
			res.pb(i*j);
		}
	}
	sort(ALL(res));
	res.erase(unique(ALL(res)),res.end());
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll a,b,c,d; cin>>a>>b>>c>>d;
		auto da=di(a),db=di(b);
		auto dc=comb(da,db);
		pair<ll,ll> res={-1,-1};
		for(auto i:dc){
			ll va=a*b;
			va/=__gcd(va,i);
			ll fa=a/i+1;
			ll fb=b/va+1;
			if(fa*i<=c&&fb*va<=d){
				res={fa*i,fb*va};
			}
		}
		cout<<res.fst<<" "<<res.snd<<"\n";
	}
	
	return 0;
}