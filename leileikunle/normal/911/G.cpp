#include <bits/stdc++.h>
//#define int long long
using namespace std;
#define endl '\n'
#define all(a) a.begin(),a.end()
using pcc = pair<char, char>;
const int N = 2e5 + 10;
int n, q;
struct node {
	int l, r, w;
	int tag[101];
	node() {
		for (int i = 1; i <= 100; i++) tag[i] = i;
	}
} tr[N * 4];
void pushdown(int u) {

	for (int i = 1; i <= 100; i++) {
		tr[u << 1].tag[i] = tr[u].tag[tr[u << 1].tag[i]];
		tr[u << 1 | 1].tag[i] = tr[u].tag[tr[u << 1 | 1].tag[i]];
	}
	for (int i = 1; i <= 100; i++) tr[u].tag[i] = i;
}

void build(int u, int l, int r) {
	tr[u].l = l, tr[u].r = r;

	if (l == r) {
		cin >> tr[u].w;
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	return;
}
void update(int u, int l, int r, int x, int y) {

	if (tr[u].l >= l and tr[u].r <= r) {
		for (int i = 1; i <= 100; i++) if (tr[u].tag[i] == x) tr[u].tag[i] = y;
		return;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid) update(u << 1, l, r, x, y);
	if (r > mid) update(u << 1 | 1, l, r, x, y);
	return;
}
void unbuild(int u, int l, int r) {
	if (l == r) {
		cout << tr[u].tag[tr[u].w] << " ";
		return;
	}
	pushdown(u);
	int mid = l + r >> 1;
	unbuild(u << 1, l, mid);
	unbuild(u << 1 | 1, mid + 1, r);
}

void solve() {

	cin >> n;
	build(1, 1, n);
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int l, r, x, y;
		cin >> l >> r >> x >> y;
		update(1, l, r, x, y);
	}
	unbuild(1, 1, n);

}
signed main() {
	cin.tie(0) -> ios::sync_with_stdio(false);
	int tt = 1;
//	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}