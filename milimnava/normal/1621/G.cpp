#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

const int N = 200005;

struct node_t { int l, r, sum[3], tag; } p[N << 2];

pair<int, int> t[N];
int a[N], good[N];

void update(int u) {
	p[u].sum[0] = (p[u << 1].sum[0] + p[u << 1 | 1].sum[0]) % mod;
	p[u].sum[1] = (p[u << 1].sum[1] + p[u << 1 | 1].sum[1]) % mod;
	p[u].sum[2] = (p[u << 1].sum[2] + p[u << 1 | 1].sum[2]) % mod;
}

void build(int u, int l, int r) {
	p[u].l = l; p[u].r = r; p[u].tag = 0;
	if (l == r) {
		p[u].sum[0] = p[u].sum[1] = p[u].sum[2] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	update(u);
}

void add_tag(int u) {
	if (!p[u].sum[0] && !p[u].sum[1] && !p[u].sum[2]) return;
	p[u].sum[1] = (p[u].sum[0] + p[u].sum[1]) % mod;
	p[u].sum[0] = 0;
	p[u].tag = 1;
}

void pushdown(int u) {
	if (p[u].tag) {
		add_tag(u << 1);
		add_tag(u << 1 | 1);
		p[u].tag = 0;
	}
}

void cover(int u, int l, int r) {
	if (l <= p[u].l && p[u].r <= r) {
		add_tag(u);
		return;
	}
	pushdown(u);
	int mid = (p[u].l + p[u].r) >> 1;
	if (mid >= l) cover(u << 1, l, r);
	if (mid + 1 <= r) cover(u << 1 | 1, l, r);
	update(u);
}

int query(int u, int l, int r, int id) {
	if (l <= p[u].l && p[u].r <= r) return p[u].sum[id];
	pushdown(u);
	int mid = (p[u].l + p[u].r) >> 1, ans = 0;
	if (mid >= l) ans = query(u << 1, l, r, id);
	if (mid + 1 <= r) ans += query(u << 1 | 1, l, r, id);
	return ans % mod;
}

void modify(int u, int x, int id, int y) {
	if (p[u].l == p[u].r) {
		p[u].sum[id] = y;
		return;
	}
	pushdown(u);
	int mid = (p[u].l + p[u].r) >> 1;
	if (mid >= x) modify(u << 1, x, id, y);
	else modify(u << 1 | 1, x, id, y);
	update(u);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) t[i] = make_pair(a[i], -i);
		int maxn = 0;
		for (int i = n; i >= 1; i--) {
			good[i] = a[i] > maxn;
			maxn = max(maxn, a[i]);
		}
		sort(t + 1, t + n + 1);
		int maxr = 0;
		build(1, 1, n);
		for (int i = n; i >= 1; i--) {
			int id = -t[i].second;
			if (id != 1 && good[id]) cover(1, 1, id - 1);
			maxr = max(maxr, id);
			int tmp[3] = {0, 0, 0}, res[3] = {0, 0, 0};
			for (int j = 0; j <= 2; j++) {
				if (id != n) {
					tmp[j] = query(1, id + 1, n, j);
				}
			}
			if (maxr > id) {
				res[1] = 1; res[2] = 1;
			} else {
				res[0] = 1;
			}
			res[2] = (tmp[1] + res[2]) % mod;
			for (int j = 0; j <= 2; j++) {
				modify(1, id, j, (res[j] + tmp[j]) % mod);
			}
		}
		cout << p[1].sum[2] << endl;
	}
	return 0;
}