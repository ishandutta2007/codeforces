#include<bits/stdc++.h>
using namespace std;
long long mod=1000000007;
long long inv[3000];
long long inverse(long long a) {
	long long g=a;
	if(inv[a]!=-1) return inv[a];
	long long b=mod-2;
	long long c=1;
	while(b>0) {
		if(b&1) c=(c*a)%mod;
		a=(a*a)%mod;
		b=b>>1;
	}
	inv[g]=c;
	return inv[g];
}
long long degs[3000];
long long a[3000];
long long k;
int n;
long long nad(long long x,long long y) {
	long long r=1;
	for(long long i=1;i<=y;i++) {
		r=(((r*(x-i+1))%mod)*inverse(i))%mod;
	}
	return r;
}
void calc()
{
	if(k==0) {
		degs[0]=1;
		return;
	}
	else {
		degs[0]=1;
		for(int i=1;i<n;i++) {
			degs[i]=nad(k-1+i,i);
		}
	}
}
int main()
{
	scanf("%d %lld",&n,&k);
	for(int i=0;i<n;i++) {
		scanf("%lld",&a[i]);
		inv[i+1]=-1;
	}
	calc();
	long long s;
	for(int i=0;i<n;i++) {
		s=0;
		for(int j=0;j<=i;j++) s+=(degs[j]*a[i-j])%mod;
		s%=mod;
		printf("%lld ",s);
	}
	return 0;
}