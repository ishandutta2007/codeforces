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

ll fact[200005];

ll comb(ll n, ll k){
	if(k>n)return 0;
	ll d=(fact[k]*fact[n-k])%MOD;
	return (fact[n]*be(d,MOD-2,MOD))%MOD;
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	fact[0]=1;
	fore(i,1,200005)fact[i]=(fact[i-1]*i)%MOD;
	if(n==2){
		cout<<0; return 0;
	}
	ll res=0;
	fore(i,n-1,m+1){
		ll t=i-1;
		t*=comb(i-2,n-3); t%=MOD;
		t*=be(2,n-3,MOD); t%=MOD;
		res+=t; res%=MOD;
	}
	cout<<res;
	return 0;
}