#include <bits/stdc++.h>
using namespace std;

const int N = 4e6 + 5;

int n, MOD;
int f[N], g[N];

int main() {
	scanf("%d%d", &n, &MOD);
	f[1] = 1;
	int sum = 0;	
	for (int i = 1; i <= n; i++) {
		(f[i] += sum) %= MOD;
		(g[i] += g[i - 1]) %= MOD;
		(f[i] += g[i]) %= MOD;
		for (int j = i + i, k = 2; j <= n; j += i, k++) {
			(g[j] += f[i]) %= MOD;
			if (j + k <= n) (g[j + k] -= f[i]) %= MOD;
		}
		(sum += f[i]) %= MOD;
	}
	printf("%d\n", (f[n] + MOD) % MOD);
}