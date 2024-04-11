#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

typedef long long int64;
typedef long double ld;

template <class T> bool bmin(T& a, T b) { return a > b ? (a = b, true) : false; }
template <class T> bool bmax(T& a, T b) { return a < b ? (a = b, true) : false; }

const int64 INF64 = 1e18;
const int INF = 1e9;

using namespace std;

struct one {
	int64 x;
	int type;
	int num;
	one(int64 x = 0, int type = 0, int num = -1) : x(x), type(type), num(num) {}
};

struct Tree {
	int n;
	vector <int> tree;
	vector <int> mod;
	
	Tree(int n) : n(n) {
		tree.resize(4 * n, 0);
		mod.resize(4 * n, 0);
	}

	void push(int v, int vl, int vr) {
		tree[v] += mod[v];
		if (vr - vl > 1) {
			mod[2 * v] += mod[v];
			mod[2 * v + 1] += mod[v];
		}
		mod[v] = 0;
	}

	void update(int v, int vl, int vr, int l, int r, int delta) {
		push(v, vl, vr);
		if (r <= vl || vr <= l) {
			return;
		}
		if (l <= vl && vr <= r) {
			mod[v] += delta;
			return;
		}
		int vm = (vl + vr) / 2;
		update(2 * v, vl, vm, l, r, delta);
		update(2 * v + 1, vm, vr, l, r, delta);
		push(2 * v, vl, vm);
		push(2 * v + 1, vm, vr);
		tree[v] = max(tree[2 * v], tree[2 * v + 1]);
	}

	int get(int v, int vl, int vr, int l, int r) {
		push(v, vl, vr);
		if (r <= vl || vr <= l) {
			return -INF;
		}
		if (l <= vl && vr <= r) {
			return tree[v];
		}
		int vm = (vl + vr) / 2;
		return max(get(2 * v, vl, vm, l, r), get(2 * v + 1, vm, vr, l, r));
	}
};

int Low_digits(vector <int64>& sa, vector <int64>& ea, vector <int64>& sb, vector <int64>& eb) {
	vector <int64> tmp;
	for (auto i : sa) {
		tmp.push_back(i);
	}
	for (auto i : ea) {
		tmp.push_back(i);
	}
	for (auto i : sb) {
		tmp.push_back(i);
	}
	for (auto i : eb) {
		tmp.push_back(i);
	}

	sort(tmp.begin(), tmp.end());
	tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());

	for (auto& i : sa) {
		i = lower_bound(tmp.begin(), tmp.end(), i) - tmp.begin();
	}
	for (auto& i : ea) {
		i = lower_bound(tmp.begin(), tmp.end(), i) - tmp.begin();
	}
	for (auto& i : sb) {
		i = lower_bound(tmp.begin(), tmp.end(), i) - tmp.begin();
	}
	for (auto& i : eb) {
		i = lower_bound(tmp.begin(), tmp.end(), i) - tmp.begin();
	}
	
	return int(tmp.size() + 1);
}

bool can_find(vector <int64>& sa, vector <int64>& ea, vector <int64>& sb, vector <int64>& eb, int n, int m) {
	vector <one> ev;
	for (int i = 0; i < n; i++) {
		ev.push_back({ sa[i], 1, i });
		ev.push_back({ ea[i], 2, i });
	}
	sort(ev.begin(), ev.end(), [](one& a, one& b) {
		return a.x < b.x || (a.x == b.x && a.type < b.type);
		});

	Tree tr = Tree(m);
	for (auto i : ev) {
		if (i.type == 1) {
			int num = i.num;
			int Min = tr.get(1, 0, m, sb[num], eb[num] + 1);
			if (Min != 0) {
				return true;
			}
		} else {
			int num = i.num;
			tr.update(1, 0, m, sb[num], eb[num] + 1, 1);
		}
	}
	return false;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	vector <int64> sa(n), ea(n), sb(n), eb(n);
	for (int i = 0; i < n; i++) {
		cin >> sa[i] >> ea[i] >> sb[i] >> eb[i];
	}

	int m = Low_digits(sa, sb, ea, eb);

	if (can_find(sa, ea, sb, eb, n, m) || can_find(sb, eb, sa, ea, n, m)) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
}