#include <cstdio>
const int MOD = 1000000007;

int x, y, n;

int main(){
	scanf("%d%d%d", &x, &y, &n);
	int f[10] = {0, x % MOD, y % MOD, (y - x) % MOD, (-x) % MOD, (-y) % MOD, (x - y) % MOD};
	printf("%d\n", (f[(n - 1) % 6 + 1] + MOD) % MOD);
	return 0;
}