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

vector<pair<ll,ll>> trans(vector<ll> a, ll m){
	vector<pair<ll,ll>> res;
	for(auto i:a){
		pair<ll,ll> p={i,1};
		while(p.fst%m==0){
			p.fst/=m;
			p.snd*=m;
		}
		if(SZ(res)==0||res.back().fst!=p.fst)res.pb(p);
		else res.back().snd+=p.snd;
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		ll k; cin>>k;
		vector<ll> b(k);
		fore(i,0,k)cin>>b[i];
		if(trans(a,m)==trans(b,m))cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}