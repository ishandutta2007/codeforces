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

bool is(ll s, ll d, ll n, ll x){
	if(x<s)return 0;
	ll c=(x-s)/d;
	if(s+c*d!=x)return 0;
	return c<n;
}

vector<ll> di(ll n){
	vector<ll> res;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
			res.pb(i);
			if(i!=n/i)res.pb(n/i);
		}
	}
	return res;
}

const ll MOD=1000000007;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll bs,bd,bn; cin>>bs>>bd>>bn;
		ll cs,cd,cn; cin>>cs>>cd>>cn;
		if(!is(bs,bd,bn,cs)||!is(bs,bd,bn,cs+cd*(cn-1))||cd%bd!=0){
			cout<<"0\n";
			continue;
		}
		auto d=di(cd);
		ll res=0,br=0;
		for(auto i:d){
			if(lcm(i,bd)!=cd)continue;
			if(!is(bs,bd,bn,cs-cd)||!is(bs,bd,bn,cs+cd*cn))br++;
			else{
				ll c=(cd-1)/i+1;
				res=(res+c*c)%MOD;
			}
		}
		if(br)cout<<"-1\n";
		else cout<<res<<"\n";
	}
	
	return 0;
}