#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

struct rectangle {
	int x1, y1, x2, y2;
	int l, r;
	rectangle(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, int l = 0, int r = 0)
		: x1(x1), y1(y1), x2(x2), y2(y2), l(l), r(r)
	{}
	void change(int val) {
		if (l == -1)
			l = val;
		else
			r = val;
	}
};

istream& operator >> (istream& in, rectangle& a) {
	cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
	a.l = a.r = -1;
	if (a.x1 == a.x2) {
		if (a.y1 > a.y2)
			swap(a.y1, a.y2);
		a.x2++, a.y2++;
	}
	else {
		if (a.x1 > a.x2)
			swap(a.x1, a.x2);
		a.y2++, a.x2++;
	}
	return in;
}

int n;
vector <rectangle> plane;
vector <int> real;

bool comp1(pair <int, int> a, pair <int, int> b) {
	return a.first < b.first || a.first == b.first && a.second < b.second;
}

void low_dig() {
	vector <pair <int, int>> tmp;
	for (int i = 0; i < n; i++) {
		tmp.push_back({ plane[i].y1, i });
		tmp.push_back({ plane[i].y2, i });
	}
	sort(tmp.begin(), tmp.end(), comp1);
	int val = 0;
	plane[tmp.begin()->second].l = 0;
	real.push_back(plane[tmp.begin()->second].y1);
	int sz = (int)tmp.size();
	for (int i = 1; i < sz; i++) {
		if (tmp[i - 1].first < tmp[i].first) {
			val++;
			real.push_back(tmp[i].first);
		}
		plane[tmp[i].second].change(val);
	}
}

struct OneEvent {
	int x, ind, type;
	OneEvent(int x = 0, int ind = 0, int type = -1)
		: x(x), ind(ind), type(type)
	{}
};

bool comp2(OneEvent a, OneEvent b) {
	return a.x < b.x || a.x == b.x && a.type > b.type;
}

struct node {
	int val;
	ll num;
	node(int val = 0, ll num = 0LL)
		: val(val), num(num)
	{}
};

node operator + (node a, node b) {
	if (a.val == b.val)
		return node(a.val, a.num + b.num);
	if (a.val < b.val)
		return node(a.val, a.num);
	return node(b.val, b.num);
}

int m;
vector <node> tree;
vector <int> mod;

inline void push(int v, int vl, int vr) {
	tree[v].val += mod[v];
	if (vr - vl > 1) {
		mod[2 * v] += mod[v];
		mod[2 * v + 1] += mod[v];
	}
	mod[v] = 0;
}

void build(int v, int vl, int vr) {
	if (vr - vl == 1) {
		tree[v].num = real[vr] - real[vl];
		return;
	}
	int vm = (vl + vr) / 2;
	build(2 * v, vl, vm);
	build(2 * v + 1, vm, vr);
	tree[v] = tree[2 * v] + tree[2 * v + 1];
}

void update(int v, int vl, int vr, int l, int r, int d) {
	push(v, vl, vr);
	if (r <= vl || vr <= l)
		return;
	if (l <= vl && vr <= r) {
		mod[v] += d;
		return;
	}
	int vm = (vl + vr) / 2;
	update(2 * v, vl, vm, l, r, d);
	update(2 * v + 1, vm, vr, l, r, d);
	tree[v] = node(tree[2 * v].val + mod[2 * v], tree[2 * v].num) + node(tree[2 * v + 1].val + mod[2 * v + 1], tree[2 * v + 1].num);
}

ll get() {
	push(1, 0, m);
	if (tree[1].val > 0LL)
		return real.back() - *real.begin();
	return real.back() - *real.begin() - tree[1].num;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	plane.resize(n);
	for (auto& i : plane)
		cin >> i;
	if (n == 0)
		return cout << "0\n", 0;
	low_dig();
	m = (int)real.size() - 1;
	tree.resize(4 * m, node());
	mod.resize(4 * m);
	build(1, 0, m);
	vector <OneEvent> events;
	for (int i = 0; i < n; i++) {
		events.push_back(OneEvent(plane[i].x1, i, 0));
		events.push_back(OneEvent(plane[i].x2, i, 1));
	}
	sort(events.begin(), events.end(), comp2);
	ll ans = 0LL;
	update(1, 0, m, plane[events.begin()->ind].l, plane[events.begin()->ind].r, 1);
	int sz = (int)events.size();
	for (int i = 1; i < sz; i++) {
		ll del = (ll)events[i].x - (ll)events[i - 1].x;
		ans += del * get();
		if (events[i].type == 1)
			update(1, 0, m, plane[events[i].ind].l, plane[events[i].ind].r, -1);
		else
			update(1, 0, m, plane[events[i].ind].l, plane[events[i].ind].r, 1);
	}
	cout << ans << '\n';
	return 0;
}