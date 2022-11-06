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

vector<ll> v;
vector<pair<ll,ll>> res;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)v.pb(i+1);
		while(SZ(v)>=3){
			ll a=v.back(); v.pop_back();
			ll b=v.back(); v.pop_back();
			ll c=v.back(); v.pop_back();
			if((a+b)%2==0){
				res.pb({a,b});
				v.pb(c);
				v.pb((a+b)/2);
			}else if((b+c)%2==0){
				res.pb({b,c});
				v.pb(a);
				v.pb((b+c)/2);
			}else if((c+a)%2==0){
				res.pb({c,a});
				v.pb(b);
				v.pb((c+a)/2);
			}
		}
		if(SZ(v)==2){
			ll a=v.back(); v.pop_back();
			ll b=v.back(); v.pop_back();
			res.pb({a,b});
			v.pb((a+b+1)/2);
		}
		cout<<v[0]<<"\n";
		for(auto i:res)cout<<i.fst<<" "<<i.snd<<"\n";
		v.clear();
		res.clear();
	}
	
	return 0;
}