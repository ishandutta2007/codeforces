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
 
ll fact[500005],facti[500005];
 
ll comb(ll n, ll k){
	if(k>n)return 0;
	return fact[n]*(facti[k]*facti[n-k]%MOD)%MOD;
}
 
int main(){FIN;
	fact[0]=1;
	fore(i,1,500005)fact[i]=(fact[i-1]*i)%MOD;
	fore(i,0,500005)facti[i]=be(fact[i],MOD-2,MOD);
	ll n,k; cin>>n>>k;
	ll res=0;
	fore(i,1,n+1){
		res=(res+comb((n-i)/i,k-1))%MOD;
	}
	cout<<res<<"\n";
	return 0;
}