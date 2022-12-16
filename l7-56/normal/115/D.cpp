#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

constexpr int maxn = 2010, mod = 1e6 + 3;
int n,f[maxn][maxn];
char s[maxn];
int dfs(int l, int r) {
	if (l > r) return 0;
	if (f[l][r] != -1) return f[l][r];
	ll val = 0;
	if (s[l] == '+' || s[l] == '-') val += dfs(l + 1, r);
	for (int k = l + 1; k < r; ++k)
		if (!isdigit(s[k]) && isdigit(s[k - 1]) && s[k + 1] != '*' && s[k + 1] != '/')
			val += 1ll * dfs(l, k - 1) * dfs(k + 1, r);
	return f[l][r] = val % mod;
}

signed main() {
//	freopen("expression.in", "r", stdin), freopen("expression.out", "w", stdout);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	memset(f, -1, sizeof f);
	for (int l = 1, r; l <= n; ++l) {
		if (!isdigit(s[l])) continue;
		for (r = l; r < n && isdigit(s[r + 1]); ++r);
		for (int i = l; i <= r; ++i)
			for (int j = i; j <= r; ++j)
				f[i][j] = 0;
		f[l][r] = 1;
		l = r;
	}
	printf("%d\n", dfs(1, n));
	return 0;
}