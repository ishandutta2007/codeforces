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
		ll n,k; cin>>n>>k;
		vector<ll> c(31);
		fore(i,0,n){
			ll x; cin>>x;
			fore(j,0,31){
				c[j]+=!!(x&(1ll<<j));
			}
		}
		ll res=0;
		for(ll j=30;j>=0;j--){
			ll val=n-c[j];
			if(val<=k){
				res+=(1ll<<j);
				k-=val;
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}