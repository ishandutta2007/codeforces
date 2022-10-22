#include<bits/stdc++.h>
using namespace std;
long long dp[2000000];
long long f[2000000];
long long fin[2000000];
long long mod=1000000007;
long long step(long long a,long long b) {
	long long c=1;
	while(b>0) {
		if(b&1) c=(c*a)%mod;
		a=(a*a)%mod;
		b=b>>1;
	}
	return c;
}
long long binom(long long n,long long k) {
	if(k>n) return 0;
	long long c=(fin[k]*fin[n-k])%mod;
	c=(c*f[n])%mod;
	return c;
}
int main() {
	long long n,m,a,b;
	scanf("%lld %lld %lld %lld",&n,&m,&a,&b);
	f[0]=1;
	long long t=max(n,m);
	for(long long i=1;i<=t;i++) f[i]=(f[i-1]*i)%mod;
	for(long long int i=0;i<=t;i++) fin[i]=step(f[i],mod-2);
	for(long long int i=1;i<=n-1;i++) {
		dp[i]=(binom(n-2,i-1)*f[i-1])%mod;
		dp[i]=(dp[i]*(i+1))%mod;
		dp[i]=(dp[i]*step(n,n-(i+1)-1))%mod;
	}
	dp[n-1]=f[n-2];
	long long s=0;
	for(long long int i=1;i<n;i++) {
		s=s+(((dp[i]*binom(m-1,i-1))%mod)*step(m,n-i-1))%mod;
		s%=mod;
	}
	printf("%lld",s);
	return 0;
}