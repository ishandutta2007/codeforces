#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

char c[23][23333];
int a[23][26], mn[1 << 23], sum[1 << 23], low[1 << 23], popc[1 << 23], EI[1 << 23];

inline int norm(int x) {
	return x >= mod ? x - mod : x;
}

inline int reduce(int x) {
	return x < 0 ? x + mod : x;
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) scanf("%s", c[i] + 1);
	for (int i = 0; i < n; i++) {
		int m = strlen(c[i] + 1);
		for (int j = 1; j <= m; j++) ++a[i][c[i][j] - 'a'];
	}
	for (int i = 1; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				low[i] = j;
				break;
			}
		}
	}
	for (int i = 1; i < (1 << n); i++) sum[i] = 1;
	for (int i = 0; i < 26; i++) {
		mn[0] = 1e9;
		for (int j = 1; j < (1 << n); j++) {
			mn[j] = min(mn[j ^ (1 << low[j])], a[low[j]][i]);
			sum[j] = 1ll * sum[j] * (mn[j] + 1) % mod;
			EI[j] = EI[j ^ (1 << low[j])] + low[j] + 1;
		}
	}
	for (int i = 1; i < (1 << n); i++) {
		popc[i] = popc[i ^ (i & -i)] + 1;
		if (popc[i] % 2 == 0) sum[i] = reduce(-sum[i]);
	}
	for (int len = 1; len < (1 << n); len <<= 1) {
		for (int i = 0; i < (1 << n); i += (len << 1)) {
			for (int j = 0; j < len; j++) {
				sum[i + j + len] = norm(sum[i + j + len] + sum[i + j]);
			}
		}
	}
	long long ans = 0;
	for (int i = 1; i < (1 << 23); i++) ans ^= 1ll * popc[i] * EI[i] * sum[i];
	cout << ans << endl;
	return 0;
}