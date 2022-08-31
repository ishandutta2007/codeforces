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

int a[510][510];
int n, m, k, q;
vector<tuple<int, int, int> > vv;
int up[510];

int check() {
	for (int i = 0; i < m; ++i)
		up[i] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			if (a[i][j])
				++up[j];
			else
				up[j] = 0;
		int cnt = 0;
		for (int j = 0; j < m; ++j) {
			if (up[j] >= k)
				++cnt;
			else
				cnt = 0;
			if (cnt >= k)
				return 1;
		}
	}
	return 0;
}

int main() {
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for (int i = 0; i < q; ++i) {
		int x, y, t;
		scanf("%d%d%d", &x, &y, &t);
		--x, --y;
		vv.push_back(make_tuple(t, x, y));
	}
	sort(vv.begin(), vv.end());
	int l = 0;
	int r = vv.size() + 1;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				a[i][j] = 0;
		for (int i = 0; i < mid; ++i)
			a[get<1>(vv[i])][get<2>(vv[i])] = 1;
		if (check())
			r = mid;
		else
			l = mid;
	}
	if (l == vv.size()) {
		cout << -1 << "\n";
	}
	else {
		cout << get<0>(vv[l]) << "\n";
	}
	return 0;
}