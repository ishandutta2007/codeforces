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

ll be(ll b, ll e, ll mod){
  ll r=1;
  while(e)if(e&1)r=(r*b)%mod,e^=1; else b=(b*b)%mod,e/=2;
  return r;
}

ll c[1000006],p[1000006];

int main(){FIN;
	ll n; cin>>n;
	vector<vector<ll>> v;
	ll nn=be(n,MOD-2,MOD);
	fore(i,0,n){
		vector<ll> vv;
		ll k; cin>>k;
		vv.pb(k);
		ll kk=(be(k,MOD-2,MOD)*nn)%MOD;
		fore(i,0,k){
			ll lle; cin>>lle; lle--;
			c[lle]++;
			p[lle]+=kk;
			if(p[lle]>MOD)p[lle]-=MOD;
			vv.pb(lle);
		}
		v.pb(vv);
	}
	ll res=0;
	fore(i,0,1000000){
		ll t=(p[i]*c[i])%MOD;
		t*=nn;	t%=MOD;
		res+=t;
		if(res>MOD)res-=MOD;
	}
	cout<<res;
	return 0;
}