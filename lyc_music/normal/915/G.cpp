#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll a=0,b=getchar(),c=1;
	while(!isdigit(b))c=b=='-'?-1:1,b=getchar();
	while(isdigit(b))a=a*10+b-'0',b=getchar();
	return a*c;
}
const int N=2e6+5,mod=1e9+7;
ll n,K,ans,f[N],a[N];
ll gg(ll x,ll y){
	ll ret=1;
	while(y){
		if(y&1)ret=ret*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ret;
}
int main(){
	n=read(),K=read();
	for(int i=1;i<=K;i++){
		a[i]=(a[i]+a[i-1])%mod;
		f[i]=(f[i]+gg(i,n)+a[i])%mod;
		for(int j=2;i*j<=K;j++)
			a[i*j]=(a[i*j]+f[i-1]+mod-f[i])%mod;
		ans=(ans+(f[i]^i))%mod;
	}
	printf("%d",ans);
	return 0;
}