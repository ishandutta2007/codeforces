#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define int long long
#define all(a) a.begin(),a.end()
using pii = pair<int, int>;
const int N = 1e6 + 10, M = N, inf = 1e18, mod = 998244353;

int h[N];
struct node {
	int l, r;
	int mx;
} tr[N * 4];
void pushup(int u) {
	tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
}
void build(int u, int l, int r) {
	tr[u] = {l, r};
	if (l == r) {
		tr[u].mx = h[l];
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
int query(int u, int l, int r) {
	if (tr[u].l >= l and tr[u].r <= r) return tr[u].mx;
	int mid = tr[u].l + tr[u].r  >> 1;
	int ans(0);
	if (l <= mid) ans = max(ans, query(u << 1, l, r));
	if (r > mid) ans = max(ans, query(u << 1 | 1, l, r));
	return ans;
}
void solve() {

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> h[i];
	build(1, 1, m);
	int q;
	cin >> q;
	while (q--) {
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		if (b > d) swap(a, c), swap(b, d);

		int flag(0);
		a = a + (n - a) / k * k;
		if ((d - b) % k != 0 or a < c
		        or (a - c) % k != 0 or query(1, b, d) >= a) flag = 1;

		if (flag) cout << "NO\n";
		else cout << "YES\n";
	}

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