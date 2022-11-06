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
	vector<ll> v[20];
	fore(i,1,200005){
		fore(j,0,20){
			if(i&(1ll<<j))v[j].pb(i);
		}
	}
	ll t; cin>>t;
	while(t--){
		ll l,r; cin>>l>>r;
		ll res=1e18;
		fore(i,0,20){
			auto c=lower_bound(ALL(v[i]),r+1)-lower_bound(ALL(v[i]),l);
			res=min(res,r-l+1-c);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}