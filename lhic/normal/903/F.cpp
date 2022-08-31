#ifndef LOCAL
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int INF = 1e9;

int n;
string s[4];
int a[10];
int dp[700];
int dp2[700];

int h[4];

int pw[] = {1, 5, 25, 125, 625};

int get() {
	return ((h[3] * 5 + h[2]) * 5 + h[1]) * 5 + h[0];
}

int gt(int x, int y) {
	return (x / pw[y]) % 5;
}

void upd(int &a, int b) {
	a = min(a, b);
}

int main() {
	cin >> n;
	for (int i = 1; i <= 4; ++i)
		cin >> a[i];
	for (int i = 3; i >= 1; --i)
		a[i] = min(a[i], a[i + 1]);
	for (int i = 0; i < 4; ++i)
		cin >> s[i];
	/*
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 256; ++j) {
			for (int k = 0; k < 4; ++k) {
				h[k] = gt(j, k);
				++h[k];
				if (h[k] == 1 && s[k][i] == '.')
					h[k] = 0;
			}
			upd(dp[i + 1][0], dp[i][j] + a[4]);
			int mx = 0;
			for (int k = 0; k < 4; ++k)
				mx = max(mx, h[k]);
			if (mx == 4)
				continue;
			upd(dp[i + 1][0], dp[i][j] + a[3] + a[3]);
			if (h[0] <= 2 || h[3] <= 2)
				upd(dp[i + 1]
		}
	}*/
	for (int k = 0; k < 625; ++k)
		dp[k] = INF;
	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 625; ++k)
				dp2[k] = INF;
			for (int k = 0; k < 625; ++k) {
				if (dp[k] == INF)
					continue;
				for (int l = 0; l < 4; ++l)
					h[l] = gt(k, l);
				++h[j];
				if (h[j] == 1 && s[j][i] == '.')
					h[j] = 0;
				for (int len = 0; j - len >= -1; ++len) {
					for (int x = j; x > j - len; --x)
						if (h[x] <= len)
							h[x] = 0;
					upd(dp2[get()], dp[k] + a[len]);
				}
			}
			for (int k = 0; k < 625; ++k)
				dp[k] = dp2[k];
		}
		for (int k = 0; k < 625; ++k) {
			if (dp[k] == INF)
				continue;
			for (int j = 0; j < 4; ++j)
				if (gt(k, j) == 4) {
					dp[k] = INF;
					break;
				}
		}
	}
	cout << dp[0] << "\n";
	return 0;
}