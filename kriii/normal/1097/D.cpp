#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const long long mod = 1000000007;
long long inv[100000] = {0,1}, fact[100000] = {1,1}, ifact[100000] = {1,1}, ans = 1; int K;

void proc(long long x, int c)
{
	long long prv[64] = {0,};
	prv[c] = 1;
	for (int k=0;k<K;k++){
		long long nxt[64] = {0,};
		for (int i=0;i<=c;i++){
			for (int j=0;j<=i;j++) nxt[j] = (nxt[j] + prv[i] * inv[i+1]) % mod;
		}
		for (int i=0;i<=c;i++) prv[i] = nxt[i];
	}

	long long s = 0, p = 1;
	for (int i=0;i<=c;i++){
		s = (s + prv[i] * p) % mod;
		p = p * x % mod;
	}
	ans = ans * s % mod;
}

int main()
{
	for (int i=2;i<100000;i++){
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
		fact[i] = fact[i-1] * i % mod;
		ifact[i] = ifact[i-1] * inv[i] % mod;
	}

	long long x; scanf ("%lld %d",&x,&K);
	for (long long i=2;i*i<=x;i++) if (x % i == 0){
		int c = 0;
		while (x % i == 0){
			x /= i;
			c++;
		}
		proc(i,c);
	}
	if (x > 1) proc(x,1);

	printf ("%lld\n",ans);

	return 0;
}