#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

map<ll,ll> mp;

int main(){FIN;
	ll q; cin>>q;
	while(q--){
		ll n; cin>>n;
		ll lle;
		fore(i,0,n){
			cin>>lle;
			mp[lle]++;
		}
		vector<pair<ll,ll>> v;
		for(auto i:mp){
			v.pb({i.snd,i.fst});
		}
		sort(ALL(v));
		reverse(ALL(v));
		ll res=0,va=4e5;
		fore(i,0,SZ(v)){
			res+=max(min(va-1,v[i].fst),0ll);
			va=max(min(va-1,v[i].fst),0ll);
		}
		cout<<res<<"\n";
		mp.clear();
	}
	return 0;
}