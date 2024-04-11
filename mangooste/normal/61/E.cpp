#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int n;
vector <int> a;

void low_dig() {
	vector <pair <int, int>> v(n);
	for (int i = 0; i < n; i++)
		v[i] = { a[i], i };
	sort(v.begin(), v.end());
	int val = 0;
	a[v[0].second] = 0;
	for (int i = 1; i < n; i++) {
		if (v[i - 1].first < v[i].first)
			val++;
		a[v[i].second] = val;
	}
}

vector <ll> tree, dp; //sum

ll get(int v, int l, int r, int tl, int tr) {
	if (tr <= l || r <= tl)
		return 0LL;
	if (tl <= l && r <= tr)
		return tree[v];
	int m = (l + r) / 2;
	return get(2 * v, l, m, tl, tr) + get(2 * v + 1, m, r, tl, tr);
}

void update(int v, int l, int r, int pos, ll val) {
	if (pos < l || pos >= r)
		return;
	if (r - l == 1) {
		tree[v] += val;
		return;
	}
	int m = (l + r) / 2;
	update(2 * v, l, m, pos, val);
	update(2 * v + 1, m, r, pos, val);
	tree[v] = tree[2 * v] + tree[2 * v + 1];
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	low_dig();
	tree.resize(4 * n);
	dp.resize(n);
	update(1, 0, n, a[0], 1LL);
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i], get(1, 0, n, a[i] + 1, n));
		update(1, 0, n, a[i], 1LL);
	}
	for (auto& i : tree)
		i = 0;
	ll ans = 0;
	update(1, 0, n, a[0], dp[0]);
	for (int i = 1; i < n; i++) {
		ans += get(1, 0, n, a[i] + 1, n);
		update(1, 0, n, a[i], dp[i]);
	}
	cout << ans << '\n';
	return 0;
}