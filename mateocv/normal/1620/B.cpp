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
		ll w,h; cin>>w>>h;
		ll res=0;
		fore(k,0,4){
			ll n; cin>>n;
			ll mini=max(w,h)+1,maxi=0;
			fore(i,0,n){
				ll x; cin>>x;
				mini=min(mini,x);
				maxi=max(maxi,x);
			}
			res=max(res,(maxi-mini)*(k<2?h:w));
		}
		cout<<res<<"\n";
	}
	
	return 0;
}