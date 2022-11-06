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
		if(n&1){
			cout<<-1<<"\n";
			continue;
		}
		vector<ll> res;
		if(n&2)res.pb(1);
		fore(i,2,61){
			if((1ll<<i)&n){
				res.pb(1);
				res.pb(1);
				fore(j,0,i-2)res.pb(0);
			}
		}
		assert(SZ(res)<=2000);
		cout<<SZ(res)<<"\n";
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}
	
	return 0;
}