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
		ll a,b,c,d; cin>>a>>b>>c>>d;
		pair<ll,ll> res={-1,-1};
		fore(x,a+1,c+1){
			ll va=a*b;
			va/=__gcd(va,x);
			ll f=b/va+1;
			if(f*va<=d){
				res={x,f*va};
			}
		}
		cout<<res.fst<<" "<<res.snd<<"\n";
	}
	
	return 0;
}