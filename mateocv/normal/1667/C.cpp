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
	ll n; cin>>n;
	ll k=(2ll*n+1)/3;
	vector<pair<ll,ll>> res;
	ll ul=0,ull=0;
	pair<ll,ll> va={n-1-k,0};
	while(va.fst>=ull){
		res.pb(va);
		va.fst+=-1;
		va.snd+=1;
		ul++;
	}
	ull=ul;
	va={n-k-2+ul,ul};
	while(va.fst>=ull){
		res.pb(va);
		va.fst+=-1;
		va.snd+=1;
		ul++;
	}
	va={ul,ul};
	while(va.fst<k){
		res.pb(va);
		va.fst+=1;
		va.snd+=1;
	}
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
	
	return 0;
}