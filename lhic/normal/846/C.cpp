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

vector<int> go[5100][5];
ll dp[5100][5];
int n;
ll a[5100];

void upd(int k, int i, int j, ll x) {
	if (dp[i + 1][k] < x) {
		dp[i + 1][k] = x;
		go[i + 1][k] = go[i][j];
		for (int t = j; t < k; ++t)
			go[i + 1][k].push_back(i);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n + 1; ++i)
		for (int j = 0; j < 4; ++j)
			dp[i][j] = -1e16;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < 3; ++i)
		go[0][i + 1] = go[0][i], go[0][i + 1].push_back(0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = j; k < 4; ++k) {
				if (k % 2 == 0)
					upd(k, i, j, dp[i][j] + a[i]);
				else
					upd(k, i, j, dp[i][j] - a[i]);
			}
		}
	}
	for (int j = 0; j < 4; ++j) {
		for (int k = j; k < 4; ++k) {
			upd(k, n, j, dp[n][j]);
		}
	}
	for (int i: go[n + 1][3])
		cout << i << " ";
	cout << "\n";
	return 0;
}