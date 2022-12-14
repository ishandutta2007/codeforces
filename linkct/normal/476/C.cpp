#include <cstdio>
typedef long long int ll;
const ll MOD = 1000000007LL, INV = 500000004LL;

int main(){
	int a_, b_;
	ll a, b;
	scanf("%d%d", &a_, &b_);
	a = a_, b = b_;
	printf("%d\n", (int)(((((b * (b - 1)) % MOD * INV) % MOD) * ((((((a + 1) * a) % MOD * INV) % MOD * b) % MOD + a) % MOD)) % MOD));
	return 0;
}