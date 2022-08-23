#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;

const ll MOD = 998244353;

ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}


int n;
int m;
int lst[1000];
ll dp[1000][1000];

ll solve(vector<int> vv) {
	dp[vv.size()][vv.size()] = 1;
	for (int i = vv.size() - 1; i >= 0; --i) {
		dp[i][i] = 1;
		for (int j = i + 1; j <= vv.size(); ++j) {
			int x = i;
			for (int k = i; k < j; ++k)
				if (vv[k] < vv[x])
					x = k;
			ll al = 0;
			for (int l = i; l <= x; ++l)
				al = (al + dp[i][l] * dp[l][x]) % MOD;
			ll ar = 0;
			for (int r = x + 1; r <= j; ++r)
				ar = (ar + dp[x + 1][r] * dp[r][j]) % MOD;
			dp[i][j] = (al * ar) % MOD;
		}
	}
	return dp[0][vv.size()];
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> n >> m;
	vector<int> vv;
	for (int i = 0; i < m; ++i) {
		int c;
		cin >> c;
		if (vv.empty() || vv.back() != c)
			vv.push_back(c);
	}
	m = vv.size();
	if (2 * n < m + 1) {
		cout << 0 << "\n";
		return 0;
	}
	for (int i = 0; i < m; ++i) {
		int fl = 0;
		for (int j = i + 1; j < m; ++j) {
			if (vv[j] < vv[i])
				fl = 1;
			if (fl && vv[j] == vv[i]) {
				cout << 0 << "\n";
				return 0;
			}
		}
	}
	for (int i = 0; i <= n; ++i)
		lst[i] = -1;
	vector<int> st;
	ll ans = 1;
	for (int i = 0; i < vv.size(); ++i) {
		int c = vv[i];
		if (lst[c] != -1) {
			vector<int> tmp;
			while (st.size() != lst[c] + 1) {
				tmp.push_back(st.back());
				st.pop_back();
			}
			ans = (ans * solve(tmp)) % MOD;
		}
		else {
			lst[c] = st.size();
			st.push_back(c);
		}
	}
	ans = (ans * solve(st)) % MOD;
	cout << ans << "\n";
	return 0;
}