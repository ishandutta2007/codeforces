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
		vector<ll> c(k);
		fore(i,0,n){
			ll x; cin>>x;
			fore(j,0,k){
				c[j]+=!!(x&(1ll<<j));
			}
		}
		ll res=0;
		for(ll i=k-1;i>=0;i--){
			res*=2;
			if(c[i]>n-c[i])res++;
		}
		cout<<res<<"\n";
	}
	
	return 0;
}