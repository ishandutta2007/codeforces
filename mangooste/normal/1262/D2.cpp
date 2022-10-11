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

typedef long long ll;
typedef long double ld;

using namespace std;

vector <int> tree;

void update(int v, int vl, int vr, int pos) {
	if (pos < vl || pos >= vr) return;
	if (vr - vl == 1) {
		tree[v]++;
		return;
	}
	int vm = (vl + vr) / 2;
	update(2 * v, vl, vm, pos);
	update(2 * v + 1, vm, vr, pos);
	tree[v] = tree[2 * v] + tree[2 * v + 1];
}

int get(int v, int vl, int vr, int pos) {
	if (vr - vl == 1) return vl;
	int vm = (vl + vr) / 2;
	if (tree[2 * v] >= pos) return get(2 * v, vl, vm, pos);
	return get(2 * v + 1, vm, vr, pos - tree[2 * v]);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector <int> a(n);
	vector <pair <int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = -i;
		a[i] = v[i].first;
	}
	sort(v.rbegin(), v.rend());
	for (int i = 0; i < n; i++) v[i].second *= (-1);
	int m;
	cin >> m;
	vector <vector <int>> e(m, vector <int>(3));
	for (int i = 0; i < m; i++) {
		int k, pos;
		cin >> k >> pos;
		e[i][0] = k, e[i][1] = pos, e[i][2] = i;
	}
	vector <int> ans(m);
	sort(e.begin(), e.end());
	tree.resize(4 * n, 0);
	for (int i = 0; i < e[0][0]; i++) {
		update(1, 0, n, v[i].second);
	}
	for (int i = 0; i < m; i++) {
		if (i != 0 && e[i - 1][0] != e[i][0]) {
			for (int j = e[i - 1][0]; j < e[i][0]; j++) {
				update(1, 0, n, v[j].second);
			}
		}
		ans[e[i][2]] = a[get(1, 0, n, e[i][1])];
	}
	for (auto i : ans) {
		cout << i << '\n';
	}
	return 0;
}