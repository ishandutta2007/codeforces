#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cout << #x << ": " << x << "\n";
const int mxN = 1e5 + 5;
int arr[mxN], segtree[mxN << 2];
void upd(int idx, int l, int r, int x, int v) {
	if (l == r) {
		segtree[idx] = min(segtree[idx], v);
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) upd(idx << 1, l, mid, x, v);
	else upd(idx << 1 | 1, mid + 1, r, x, v);
	segtree[idx] = min(segtree[idx << 1], segtree[idx << 1 | 1]);
}
int qry(int idx, int l, int r, int x, int y) {
	if (l > y || r < x || l > r) return 1e18;
	if (x <= l && r <= y) return segtree[idx];
	int mid = (l + r) >> 1;
	return min(qry(idx << 1, l, mid, x, y), qry(idx << 1 | 1, mid + 1, r, x, y));
}
void solve() { 
	// i will write my code here, or i will sleep like sleep.out
	memset(segtree, 0x3f, sizeof segtree);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	upd(1, 0, n, 0, 1);
	int ans = 0;
	for (int i = 2; i <= n; i++) {
		int cur = min(qry(1, 0, n, 0, arr[i] - 1), qry(1, 0, n, arr[i] + 1, n)) + 1;
		cur = min(cur, qry(1, 0, n, arr[i], arr[i])) + ans;
		if (arr[i - 1] != arr[i]) ans++;
		upd(1, 0, n, arr[i - 1], cur - ans);
	}
	cout << segtree[1] + ans << "\n";
}
int32_t main() {
    clock_t t1 = clock();
	#ifndef ONLINE_JUDGE
       freopen("wake.in", "r", stdin);
       freopen("sleep.out", "w", stdout);
    #endif 
	// int T;cin >> T;while (T--)
	solve();
    // cout << "Time used: " << clock() - t1 << " ms\n";
	return 0;
}