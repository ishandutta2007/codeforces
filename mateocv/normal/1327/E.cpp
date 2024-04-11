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

const ll MOD=998244353;

ll fpow(ll b, ll e, ll mod){
  ll r=1;
  while(e)if(e&1)r=(r*b)%mod,e^=1; else b=(b*b)%mod,e/=2;
  return r;
}

int main(){FIN;
	ll n; cin>>n;
	vector<ll> res;
	res.pb(10);
	ll carry=20;
	ll plane=10;
	fore(i,0,n-1){
		ll tot=((i+2)*fpow(10,i+2,MOD))%MOD;
		res.pb((tot-carry+MOD)%MOD);
		plane+=res.back();
		//if(plane>=MOD)plane-=MOD;
		plane%=MOD;
		carry+=plane;
		carry+=res.back();
		carry%=MOD;
		//if(carry>=MOD)carry-=MOD;
	}
	reverse(ALL(res));
	for(auto i:res)cout<<i<<" ";
	
	return 0;
}