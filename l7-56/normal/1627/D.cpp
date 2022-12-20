#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e6 + 10;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int n,a[maxn],f[maxn],ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		f[a[i]] = 1;
	}
	for (int i = 1000000; i >= 1; --i) {
		if (f[i]) continue;
		int res = 0;
		for (int j = 2; i * j <= 1000000; ++j)
			if (f[i * j]) res = gcd(res, i * j);
		if (res == i) f[i] = 1, ans++;
	}
	printf("%d\n", ans);
	return 0;
}