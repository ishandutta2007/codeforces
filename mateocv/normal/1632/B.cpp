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
		ll pot=(1ll<<(31-__builtin_clz(n-1)));
		vector<ll> res;
		fore(i,1,pot)res.pb(i);
		res.pb(0);
		res.pb(pot);
		fore(i,pot+1,n)res.pb(i);
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}
	
	return 0;
}