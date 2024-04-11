#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 110;
int n,a[maxn],w[maxn][maxn],f[maxn];
void work() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int l = 1; l <= n; ++l)
		for (int r = 1; r <= n; ++r) {
			bitset <maxn> v;
			for (int i = l; i <= r; ++i)
				if (a[i] <= 100) v[a[i]] = 1;
			for (w[l][r] = 0; v[w[l][r]]; ++w[l][r]);
		}
	int ans = 0;
	for (int l = 1; l <= n; ++l) {
		f[l - 1] = 0;
		for (int r = l; r <= n; ++r) {
			f[r] = 0;
			for (int j = l - 1; j < r; ++j)
				f[r] = max(f[r], f[j] + w[j + 1][r] + 1);
			ans += f[r];
		}
	}
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) work();
	return 0;
}