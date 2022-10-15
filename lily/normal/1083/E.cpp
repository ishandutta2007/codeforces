#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second

#define N 1001011

struct node {
	LL x, y, a;
	bool operator < (const node &b) const {
		return x < b.x;
	}
} a[N];

int n;
LL dp[N];

inline bool trans(const int &i, const int &j) {
	LL v = dp[j] + LL(a[i].x) * a[i].y - LL(a[j].x) * a[i].y - a[i].a;
	if (v >= dp[i]) return dp[i] = v, 1;
	else return 0;
}

void solve(int l, int r, int _l, int _r) {
	if (l > r) return;
	int mid = (l + r) >> 1, p = _l;
	for (int i = _l; i <= min(mid, _r); i++) if (trans(mid, i - 1)) p = i;
	solve(l, mid - 1, _l, p);
	solve(mid + 1, r, p, _r);
}

void lbn(int l, int r) {
	if (l == r) {
		solve(l, r, l, r);
		return;
	}
	int mid = (l + r) >> 1;
	lbn(l, mid);
	solve(mid + 1, r, l, r);
	lbn(mid + 1, r);
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		LL x, y, v;
		scanf("%lld%lld%lld", &x, &y, &v);
		a[i] = {x, y, v};
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) dp[i] = (LL)a[i].x * a[i].y - a[i].a;
	lbn(1, n);
	LL ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
	cout << ans << endl;
}