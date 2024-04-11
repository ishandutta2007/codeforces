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
		ll n; cin>>n;
		vector<ll> a(n); 
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		vector<pair<ll,ll>> v;
		for(auto i:a){
			if(!SZ(v)||v.back().fst!=i)v.pb({i,1});
			else v.back().snd++;
		}
		if(SZ(v)==1)cout<<n/2<<"\n";
		else{
			ll res=0;
			ll va=0;
			fore(i,1,SZ(v)){
				va+=v[i-1].snd;
				res=max(res,va*(n-va));
			}
			cout<<res<<"\n";
		}
	}
	
	return 0;
}