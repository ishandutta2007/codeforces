// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int N = 2001;
int n, m;
ll k, l;
char c[N][N];
int s[N][N], t[N][N];

ll get(ll x, ll y, ll k, ll l, int f = 0) {
	if (x <= n && y <= m) {
		return (f ? t[x][y] : s[x][y]);
	}
	k /= 2;
	l /= 2;
	if (x <= k && y <= l) {
		return get(x, y, k, l, f);
	}
	if (x <= k) {
		return x * l / 2 + get(x, y - l, k, l, f ^ 1);
	}
	if (y <= l) {
		return y * k / 2 + get(x - k, y, k, l, f ^ 1);
	}
	return (k * l + (x - k) * l + k * (y - l)) / 2 + get(x - k, y - l, k, l, f);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c[i][j];
		}
	}
	for (int i = 1; i <= n * 2; i++) {
		for (int j = 1; j <= m * 2; j++) {
			int x = c[i > n ? i - n : i][j > m ? j - m : j] - '0';
			if (i > n) {
				x ^= 1;
			}
			if (j > m) {
				x ^= 1;
			}
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x;
			t[i][j] = t[i - 1][j] + t[i][j - 1] - t[i - 1][j - 1] + 1 - x;
		}
	}
	n *= 2;
	m *= 2;
	k = n;
	l = m;
	while (k < 1e9 || l < 1e9) {
		k *= 2;
		l *= 2;
	}
	while (q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << get(x2, y2, k, l) - get(x1 - 1, y2, k, l) - get(x2, y1 - 1, k, l) + get(x1 - 1, y1 - 1, k, l) << '\n';
	}
	return 0;
}