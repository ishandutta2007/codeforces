#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct segmentTree {
	int n;
	vector<int> tree;

	segmentTree(vector<int> a = {1}) : n(a.size()) {
		tree.resize(4 * n);
		build(0, 0, n, a);
	}

	void build(int v, int vl, int vr, vector<int> &a) {
		if (vr - vl == 1) {
			tree[v] = a[vl];
			return;
		}
		int vm = (vl + vr) / 2;
		build(2 * v + 1, vl, vm, a);
		build(2 * v + 2, vm, vr, a);
		tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
	}

	int get_minimum(int L, int R) {
		return get(0, 0, n, L, R);
	}

	int get(int v, int vl, int vr, int L, int R) {
		if (R <= vl || vr <= L)
			return INF;
		if (L <= vl && vr <= R)
			return tree[v];
		int vm = (vl + vr) / 2;
		return min(get(2 * v + 1, vl, vm, L, R), get(2 * v + 2, vm, vr, L, R));
	}
};

struct fenwik {
	int n, m;
	vector<vector<int>> bit;

	fenwik(int n = 0, int m = 0) : n(n), m(m) {
		bit.resize(n + 1, vector<int>(m + 1, 0));
	}

	int get(int x, int y) {
		int sum = 0;
		for (int i = x; i; i -= i & -i)
			for (int j = y; j; j -= j & -j)
				sum += bit[i][j];

		return sum;
	}

	int get_sum(int x1, int y1, int x2, int y2) {
		// cout << "get_sum " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
		x2++, y2++;
		// cout << get(x2, y2) << ' ' << get(x2, y1) << ' ' << get(x1, y2) << ' ' << get(x1, y1) << endl;
		return get(x2, y2) - get(x2, y1) - get(x1, y2) + get(x1, y1);
	}

	void increase(int x, int y) {
		// cout << "increasing " << x << ' ' << y << endl;
		for (int i = x + 1; i <= n; i += i & -i)
			for (int j = y + 1; j <= m; j += j & -j)
				bit[i][j]++;
	}
};

struct pos {
	int x, y;
	int64_t need;
};


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, m, a, b;
	cin >> n >> m >> a >> b;
	vector<vector<int>> grid(n, vector<int>(m));
	for (auto &xs : grid)
		for (auto &x : xs)
			cin >> x;

	vector<vector<int64_t>> pref(n + 1, vector<int64_t>(m + 1, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + grid[i][j];

	auto get_sum = [&](int x1, int y1, int x2, int y2) {
		x2++, y2++;
		return pref[x2][y2] - pref[x2][y1] - pref[x1][y2] + pref[x1][y1];
	};

	vector<vector<int>> right(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		segmentTree tree(grid[i]);
		for (int j = 0; j + b <= m; j++)
			right[i][j] = tree.get_minimum(j, j + b);
	}

	vector<segmentTree> trees(m);
	for (int j = 0; j < m; j++) {
		vector<int> now;
		for (int i = 0; i < n; i++)
			now.push_back(right[i][j]);

		trees[j] = segmentTree(now);
	}

	vector<pos> all;
	for (int i = 0; i + a <= n; i++)
		for (int j = 0; j + b <= m; j++)
			all.push_back({i, j, get_sum(i, j, i + a - 1, j + b - 1) - int64_t(a) * b * trees[j].get_minimum(i, i + a)});

	sort(all.begin(), all.end(), [](pos &a, pos &b) {
		if (a.need < b.need)
			return true;
		if (b.need < a.need)
			return false;
		return a.x < b.x || a.x == b.x && a.y < b.y;
	});

	fenwik bit(n, m);
	vector<pos> ans;
	for (auto [x, y, need] : all) {
		int sum = bit.get_sum(x, y, x + a - 1, y + b - 1);
		// cout << x << ' ' << y << ' ' << sum << endl;
		if (sum)
			continue;

		bit.increase(x, y);
		bit.increase(x, y + b - 1);
		bit.increase(x + a - 1, y);
		bit.increase(x + a - 1, y + b - 1);

		ans.push_back({x, y, need});
	}

	cout << ans.size() << '\n';
	for (auto x : ans)
		cout << x.x + 1 << ' ' << x.y + 1 << ' ' << x.need << '\n';
}