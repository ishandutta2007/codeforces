#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int mod = 998244353;
void work() {
	int n, ans = 1; scanf("%d", &n);
	if (n & 1) return printf("0\n"), void();
	for (int i = 1; i <= n / 2; ++i) ans = 1ll * ans * i % mod;
	ans = 1ll * ans * ans % mod;
	printf("%d\n", ans);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}