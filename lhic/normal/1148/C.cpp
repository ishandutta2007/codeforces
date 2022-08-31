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


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int N = 310000;

int n;
int p[N];
int q[N];

vector<pair<int, int>> ans;

void sw(int x, int y) {
	if (x == y)
		return;
	swap(p[x], p[y]);
	q[p[x]] = x;
	q[p[y]] = y;
	ans.emplace_back(x, y);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> p[i], --p[i], q[p[i]] = i;
	int m = n / 2;
	for (int i = 1; i < n - 1; ++i) {
		int x = q[i];
		if (x == i)
			continue;
		if (x < m)
			sw(x, n - 1), x = n - 1;
		else
			sw(0, x), x = 0;
		if (abs(x - i) >= m)
			sw(x, i);
		else {
			sw(0, n - 1);
			x ^= n - 1;
			sw(x, i);
		}
	}
	if (p[0] != 0)
		sw(0, n - 1);
	cout << ans.size() << "\n";
	for (auto p: ans)
		cout << p.first + 1 << " " << p.second + 1 << "\n";
	return 0;
}