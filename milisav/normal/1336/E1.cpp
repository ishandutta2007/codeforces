#include<bits/stdc++.h>
#define maxn 6000000
using namespace std;
long long n,m;
long long sv;
long long a[maxn];
long long p[maxn];
long long mk[maxn];
long long si[600000][40];
long long mod=998244353;
int main() {
	scanf("%lld %lld",&n,&m);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	long long k=0;
	bool fn;
	for(long long j=m-1;j>=0;j--) {
		fn=false;
		long long l=-1;
		for(int i=k;i<n;i++) {
			if(a[i]&(1ll<<j)) {
				fn=true;
				l=i;
			}
		}
		if(!fn) continue;
		swap(a[k],a[l]);
		mk[k]=j;
		k++;
		for(int i=k;i<n;i++) {
			if((a[i])&(1ll<<j)) a[i]^=a[k-1];
		}
	}
	long long t=n-k;
	long long ans=1;
	for(int i=0;i<t;i++) ans=(ans*2)%mod;
	if(k==0) {
		p[0]=ans;
		for(long long i=0;i<=m;i++) printf("%lld ",p[i]);
		return 0;
	}
	sv=min(24ll,k);
	long long cn=12;
	for(long long i=0;i<(1ll<<sv);i++) {
		long long t=0;
		for(long long j=0;j<sv;j++) {
			if(i&(1ll<<j)) t^=a[j];
		}
		long long l=cn;
		long long pi=t>>l;
		long long a1=__builtin_popcountll(pi);
		pi=t&((1ll<<l)-1ll);
		si[pi][a1]++;
	}
	long long cv=k-sv;
	for(long long i=0;i<(1ll<<cv);i++) {
		long long t=0;
		for(long long j=0;j<cv;j++) {
			if(i&(1ll<<j)) t^=a[sv+j];
		}
		for(long long j=0;j<(1ll<<cn);j++) {
			for(int k=0;k<=m;k++) p[k+__builtin_popcountll(t^j)]+=si[j][k];
		}
	}
	for(long long i=0;i<=m;i++) {
		p[i]=p[i]%mod;
		p[i]=(p[i]*ans)%mod;
	}
	for(long long i=0;i<=m;i++) printf("%lld ",p[i]);
	return 0;
}