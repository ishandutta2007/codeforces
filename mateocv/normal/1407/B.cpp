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
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll maxi=0;
		vector<ll> res;
		fore(i,0,n)maxi=max(maxi,a[i]);
		res.pb(maxi);
		fore(i,0,n){
			if(a[i]==maxi){
				a[i]=-1;
				break;
			}
		}
		ll tot=n-1;
		ll g=maxi;
		while(tot>0){
			ll maxig=0;
			fore(i,0,n){
				if(a[i]!=-1){
					maxig=max(maxig,__gcd(g,a[i]));
				}
			}
			fore(i,0,n){
				if(a[i]!=-1&&__gcd(g,a[i])==maxig){
					res.pb(a[i]);
					a[i]=-1; tot--;
				}
			}
			g=__gcd(g,maxig);
		}
		for(auto i:res)cout<<i<<" "; cout<<"\n";
	}
	
	return 0;
}