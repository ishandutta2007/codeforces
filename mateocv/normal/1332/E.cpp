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

ll be(ll b, ll e, ll mod){
  ll r=1;
  while(e)if(e&1)r=(r*b)%mod,e^=1; else b=(b*b)%mod,e/=2;
  return r;
}

int main(){FIN;
	ll n,m,l,r; cin>>n>>m>>l>>r;
	ll p=(r-l+1)/2+(l%2==0&&(r-l+1)%2==1);
	ll i=(r-l+1)/2+(l%2==1&&(r-l+1)%2==1);
	assert(p+i==r-l+1);
	if(m*n%2==1){
		cout<<be(r-l+1,m*n,MOD); return 0;
	}
	ll res=be(((((p-i))%MOD)+MOD)%MOD,m*n,MOD)+be((p+i)%MOD,m*n,MOD);
	res%=MOD;
	res*=be(2,MOD-2,MOD);
	res%=MOD;
	assert(0<=res&&res<MOD);
	cout<<res;
	return 0;
}