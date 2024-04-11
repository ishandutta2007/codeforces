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

ll MOD=998244353;

ll fact[200005];

ll be(ll b, ll e, ll mod){
  ll r=1;
  while(e)if(e&1)r=(r*b)%mod,e^=1; else b=(b*b)%mod,e/=2;
  return r;
}

ll comb(ll n, ll k){
	if(k>n)return 0;
	return fact[n]*be(fact[k]*fact[n-k]%MOD,MOD-2,MOD)%MOD;
}

int main(){FIN;
	ll n, k; cin>>n>>k;
	fact[0]=1;
	fore(i,1,200005)fact[i]=fact[i-1]*i%MOD;
	if(k==0){
		cout<<fact[n];
		return 0;
	}
	if(n<=k){
		cout<<0;
		return 0;
	}
//cout<<"AAAAAAAAAA";
	vector<ll> v;
	fore(i,0,n)v.pb(be(n-i,n,MOD));
	//for(auto i:v)cout<<i<<" "; cout<<"\n";
	ll res=v[k];
	//cout<<res<<"\n";
	fore(i,k+1,n){
		if((i-k)%2==1)res=(res-(comb(n-k,(i-k))*v[i])%MOD+MOD)%MOD;
		else res=(res+(comb(n-k,(i-k))*v[i])%MOD+MOD)%MOD;
	}
	cout<<(res*comb(n,k)*2ll)%MOD;
	return 0;
}