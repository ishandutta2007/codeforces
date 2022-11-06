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
		vector<ll> a[2];
		fore(i,0,n){
			ll x; cin>>x;
			a[x&1].pb(x);
		}
		vector<ll> v;
		for(auto i:a[0])v.pb(i);
		for(auto i:a[1])v.pb(i);
		ll res=0;
		fore(i,0,SZ(v)){
			fore(j,i+1,SZ(v)){
				res+=(__gcd(v[i],2ll*v[j])>1);
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}