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

ll MOD=1000000007;

ll fact[1000006];

ll be(ll b, ll e, ll mod){
  ll r=1;
  while(e)if(e&1)r=(r*b)%mod,e^=1; else b=(b*b)%mod,e/=2;
  return r;
}

int main(){FIN;
	ll n; cin>>n;
	fact[0]=1;
	fore(i,1,1000006)fact[i]=fact[i-1]*i%MOD;
	ll res=fact[n];
	res=(res-be(2,n-1,MOD)+MOD)%MOD;
	cout<<res<<"\n";
	
	return 0;
}