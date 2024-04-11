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

ll MOD=998244353;

ll a[300005];

ll fact[300005];

ll be(ll b, ll e, ll mod){
  ll r=1;
  while(e)if(e&1)r=(r*b)%mod,e^=1; else b=(b*b)%mod,e/=2;
  return r;
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,2*n)cin>>a[i];
	fact[0]=1;
	fore(i,1,300005)fact[i]=fact[i-1]*i%MOD;
	sort(a,a+2*n);
	ll comb=fact[2*n]*be(fact[n]*fact[n]%MOD,MOD-2,MOD)%MOD;
	//cout<<comb<<"\n";
	ll res=0;
	fore(i,0,n){
		res=(res+comb*a[i+n])%MOD;
	}
	fore(i,0,n){
		res=(res-(comb*a[i]%MOD)+MOD)%MOD;
	}
	cout<<res<<"\n";
	return 0;
}