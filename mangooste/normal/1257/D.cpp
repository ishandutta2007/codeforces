#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <iomanip>
#include <string>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <cstdio>
#include <ctime>

typedef long long ll;
typedef long double ld;

using namespace std;

struct Tree {
	vector <int> tree;
	void build(int v, int vl, int vr, vector <int>& a) {
		if (vr - vl == 1) {
			tree[v] = a[vl];
			return;
		}
		int vm = (vl + vr) / 2;
		build(2 * v, vl, vm, a);
		build(2 * v + 1, vm, vr, a);
		tree[v] = max(tree[2 * v], tree[2 * v + 1]);
	}
	int get(int v, int vl, int vr, int l, int r) {
		if (r <= vl || vr <= l) {
			return -1e9;
		}
		if (l <= vl && vr <= r) {
			return tree[v];
		}
		int vm = (vl + vr) / 2;
		return max(get(2 * v, vl, vm, l, r), get(2 * v + 1, vm, vr, l, r));
	}
};

int solve() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int m;
	cin >> m;
	vector <pair <int, int>> v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	Tree tA;
	tA.tree.resize(4 * n);
	tA.build(1, 0, n, a);
	vector <int> p(m), s(m);
	for (int i = 0; i < m; i++) {
		p[i] = v[i].first;
		s[i] = v[i].second;
	}
	Tree tV;
	tV.tree.resize(4 * m);
	tV.build(1, 0, m, s);
	int ans = 0, pos = 0, maxR = *max_element(s.begin(), s.end());
	while (pos < n) {
		ans++;
		int l = pos - 1, r = pos + maxR;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			int need = tA.get(1, 0, n, pos, mid + 1);
			int ind = lower_bound(p.begin(), p.end(), need) - p.begin();
			if (ind == m) {
				r = mid;
				continue;
			}
			int d = tV.get(1, 0, m, ind, m);
			if (d >= mid - pos + 1) {
				l = mid;
			}
			else {
				r = mid;
			}
		}
		if (r == pos) {
			return -1;
		}
		pos = l + 1;
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);

	int t;
	cin >> t;
	while (t--) {
		cout << solve() << '\n';
	}
	return 0;
}