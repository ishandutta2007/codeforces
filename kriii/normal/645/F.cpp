#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

const long long mod = 1000000007;
long long inv[200020],fact[200020],ifact[200020];
int mob[1000001],vmob[1000001],cnt[1000001]; long long sum;
int n,K,q;

long long comb(long long n, long long k)
{
	if (n < 0 || k < 0 || n < k) return 0;
	return fact[n] * ifact[k] % mod * ifact[n-k] % mod;
}

void add(int x)
{
	for (int i=1;;i++){
		int a = x / i, b = x % i;
		if (i > a) break;
		if (b == 0){
			if (vmob[i]){
				sum = (sum + mod - vmob[i] * comb(cnt[i],K) % mod) % mod;
				cnt[i]++;
				sum = (sum + mod + vmob[i] * comb(cnt[i],K) % mod) % mod;
			}
			if (vmob[a] && a != i){
				sum = (sum + mod - vmob[a] * comb(cnt[a],K) % mod) % mod;
				cnt[a]++;
				sum = (sum + mod + vmob[a] * comb(cnt[a],K) % mod) % mod;
			}
		}
	}
}

int main()
{
	inv[1] = fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
	for (int i=2;i<=200000;i++){
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
		fact[i] = fact[i-1] * i % mod;
		ifact[i] = ifact[i-1] * inv[i] % mod;
	}

	mob[1] = 1;
	for (int i=1;i<=1000000;i++) if (mob[i]){
		for (int j=i*2;j<=1000000;j+=i) mob[j] -= mob[i];
	}
	for (int i=1;i<=1000000;i++){
		for (int j=i,a=1;j<=1000000;j+=i,a++){
			vmob[j] = (vmob[j] + mod + mob[a] * i) % mod;
		}
	}

	scanf ("%d %d %d",&n,&K,&q);
	for (int i=0;i<n;i++){
		int x; scanf ("%d",&x); add(x);
	}
	for (int i=0;i<q;i++){
		int x; scanf ("%d",&x); add(x);
		printf ("%lld\n",sum);
	}

	return 0;
}