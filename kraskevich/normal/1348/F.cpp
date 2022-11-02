#include <bits/stdc++.h>

using namespace std;

const int INF = static_cast<int>(1e9);
const int N = 200 * 1000 + 10;
 
int a[N];
int b[N];
int inv[N];
pair<int, int> tree[4 * N + 42];
int n;

void build_tree(int i, int l, int r) {
	if (l + 1 == r) {
		tree[i] = {a[inv[l]], l};
		return;
	}
	int m = (l + r) / 2;
	build_tree(2 * i + 1, l, m);
	build_tree(2 * i + 2, m, r);
	tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
}

pair<int, int> get_min(int i, int l, int r, int tl, int tr) {
	if (l >= r) {
		return {INF, -1};
	}
	if (l == tl && r == tr) {
		return tree[i];
	}
	int m = (tl + tr) / 2;
	auto l_res = get_min(2 * i + 1, l, min(r, m), tl, m);
	auto r_res = get_min(2 * i + 2, max(m, l), r, m, tr);
	return min(l_res, r_res);
}
 
vector<int> build_solution() {
	vector<vector<pair<int, int>>> open(n);
	for (int i = 0; i < n; i++) {
		open[a[i]].push_back({b[i], i});
	}
	set<pair<int, int>> q;
	vector<int> res(n);
	for (int i = 0; i < n; i++) {
		for (auto kv : open[i]) {
			q.insert(kv);
		}
		res[q.begin()->second] = i;
		q.erase(q.begin());
	}
	return res;
}

void print(const vector<int>& vs) {
	for (int v : vs) {
		cout << v + 1 << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		a[i]--;
		b[i]--;
	}
	auto res = build_solution();
	for (int i = 0; i < n; i++) {
		inv[res[i]] = i;
	}
	build_tree(0, 0, n);
	for (int i = 0; i < n; i++) {
		int r = b[inv[i]];
		auto [_, cand] = get_min(0, i + 1, r + 1, 0, n);
		if (cand == -1) {
			continue;
		}
		if (a[inv[cand]] <= i) {
			cout << "NO\n";
			print(res);
			swap(res[inv[i]], res[inv[cand]]);
			print(res);
			return 0;
		}
	}
	cout << "YES\n";
	print(res);
}