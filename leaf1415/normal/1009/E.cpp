#include <iostream>
#include <stdio.h>
#define llint long long 
#define mod 998244353

using namespace std;

llint n;
llint a[1000005];
llint beki[1000005];

int main(void)
{
	llint mul = 1;
	for(int i = 0; i < 1000005; i++) beki[i] = mul, mul *= 2, mul %= mod;
	
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	
	llint ans = a[1] * beki[n-1] % mod;
	for(int i = 2; i <= n; i++){
		ans += (a[i] * beki[n-i]) % mod;
		ans %= mod;
	}
	llint sum = 0;
	for(int i = 2; i <= n; i++){
		int j = i-1;
		sum += a[j] * beki[n-j-1] % mod;
		sum %= mod;
		ans += sum;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}