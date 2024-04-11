#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define fast_allocator_memory 200'000'000

#ifdef fast_allocator_memory
int allocator_pos = 0;
char allocator_memory[(int)fast_allocator_memory];
inline void* operator new (size_t n) {
	char* res = allocator_memory + allocator_pos;
	allocator_pos += n;
	return (void*)res;
}
inline void operator delete (void*) noexcept {}
#endif

const int INF = 1e9;

vector<int> tree, mod;

void build(int v, int vl, int vr, vector<int> &vals) {
	mod[v] = 0;
	if (vr - vl == 1) {
		tree[v] = vals[vl];
		return;
	}
	int vm = (vl + vr) / 2;
	build(2 * v + 1, vl, vm, vals);
	build(2 * v + 2, vm, vr, vals);
	tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
}

inline void push(int v) {
	if (!mod[v]) return;
	tree[v] += mod[v];
	mod[2 * v + 1] += mod[v];
	mod[2 * v + 2] += mod[v];
	mod[v] = 0;
}

void add(int v, int vl, int vr, int L, int R, int delta) {
	if (R <= vl || vr <= L) return;
	if (L <= vl && vr <= R) {
		mod[v] += delta;
		return;
	}
	push(v);
	int vm = (vl + vr) / 2;
	add(2 * v + 1, vl, vm, L, R, delta);
	add(2 * v + 2, vm, vr, L, R, delta);
	tree[v] = min(tree[2 * v + 1] + mod[2 * v + 1], tree[2 * v + 2] + mod[2 * v + 2]);
}

int get(int v, int vl, int vr, int L, int R) {
	if (R <= vl || vr <= L) return INF;
	if (L <= vl && vr <= R) return tree[v] + mod[v];
	push(v);
	int vm = (vl + vr) / 2;
	return min(get(2 * v + 1, vl, vm, L, R), get(2 * v + 2, vm, vr, L, R));
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	getline(cin, a[0]);
	for (auto &x : a) getline(cin, x);

	vector<vector<int>> up(n, vector<int>(m, 1));
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i - 1][j] != a[i][j]) continue;
			up[i][j] = up[i - 1][j] + 1;
		}
	}
	vector<vector<int>> down(n, vector<int>(m, 1));
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			if (a[i + 1][j] != a[i][j]) continue;
			down[i][j] = down[i + 1][j] + 1;
		}
	}
	vector<vector<int>> left(n, vector<int>(m, 1));
	for (int j = 1; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (a[i][j - 1] != a[i][j]) continue;
			left[i][j] = left[i][j - 1] + 1;
		}
	}
	vector<vector<int>> right(n, vector<int>(m, 1));
	for (int j = m - 2; j >= 0; j--) {
		for (int i = 0; i < n; i++) {
			if (a[i][j + 1] != a[i][j]) continue;
			right[i][j] = right[i][j + 1] + 1;
		}
	}

	tree.resize(4 * m);
	mod.resize(4 * m);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		vector<int> vals(m);
		for (int j = 0; j < m; j++) vals[j] = min(up[i][j], down[i][j]) + j + 1;
		build(0, 0, m, vals);
		for (int j = 0; j < m; j++) {
			add(0, 0, m, 0, j, 1);
			add(0, 0, m, j, m, -1);
			int now = tree[0] + mod[0];
			if (now > left[i][j]) now = left[i][j];
			if (now > right[i][j]) now = right[i][j];
			ans += now;
		}
	}
	cout << ans << '\n';
}