#include<iostream>
#include<cstdio>
#define ll long long
#define mod 1000003
using namespace std;
ll n,m,fac[mod],inv[mod];
ll calc(ll x,ll y){
	if(!y)return 1;if (x<y) return 0;
	if (x<mod) return fac[x]*inv[y]%mod*inv[x-y]%mod;
		return calc(x/mod,y/mod)*calc(x%mod,y%mod)%mod;
}
int main(){
	cin>>n>>m;fac[0]=1; ll i;
	for (i=1; i<mod; i++) fac[i]=fac[i-1]*i%mod;
	inv[0]=inv[1]=1;
	for (i=2; i<mod; i++) inv[i]=mod-inv[mod%i]*(mod/i)%mod;
	for(i=2;i<mod;i++)inv[i]=inv[i-1]*inv[i]%mod; ll ans=0;
	for (i=1; i<=n; i++)ans=(ans+calc(m+i-1,m-1))%mod;printf("%d\n",ans);
	return 0;
}