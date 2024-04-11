#include<bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;
const int maxn = 2e6+50;
ll fac[maxn];
ll inv[maxn];
const int mod = 1e9+7;
ll qpow(long long a,long long b) {
	ll ans=1;
	ll k=a;
	while(b) {
		if(b&1)ans=ans*k%mod;
		k=k*k%mod;
		b>>=1;
	}
	return (ans+mod)%mod;
}
void init(int xx) {
	long long it;
	fac[0]=1;
	inv[0]=1;
	fac[1]=1;
	inv[1]=1;
	for(int i=2; i<=xx; i++)
		fac[i]=fac[i-1]*i%mod,inv[i]=mod-(mod/i)*inv[mod%i]%mod;
	for(int i=1; i<=xx; i++)
		inv[i]=inv[i-1]*inv[i]%mod;
}
ll C(ll n,ll m) {
	if (n<m||m<0) return 0;
	return  (fac[n]*inv[m]%mod*inv[n-m]%mod+mod)%mod;
}
signed main() {
	init(1005);
	int n;
	double xx;
	cin >> n >> xx;
	for(int x=0;x<=n;x++) {
		int p0 = C(n-x,3);
		int p1 = C(n-x,2)*x;
		int p2 = C(x,2)*(n-x);
		int p3 = C(x,3);
		double p = (0.5*p1+p2+p3)/(1.0*p0+p1+p2+p3);
		if(p-xx>1e-10 || abs(p-xx)<1e-10) {
			printf("%lld\n",x);
			return 0;
		}
	}
	
}