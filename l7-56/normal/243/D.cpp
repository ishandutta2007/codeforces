#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
#define fir first
#define sec second

const int maxn = 1e3 + 10, maxm = 2e6 + 10, inf = 1e9 + 7;
int n, m, a[maxn][maxn], vx, vy, pos[maxn][maxn], b[maxm];
ll ans;

struct SegTreeBeats {
	int mn[maxm << 2], tag[maxm << 2];
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) >> 1)
	void push_up(int rt) { mn[rt] = max(tag[rt], min(mn[ls], mn[rs])); }
	void update(int rt, int l, int r, int L, int R, int val) {
		if (L > R || L > r || R < l) return;
		if (L <= l && r <= R)
			return mn[rt] = max(mn[rt], val), tag[rt] = max(tag[rt], val), void();
		update(ls, l, mid, L, R, val), update(rs, mid + 1, r, L, R, val), push_up(rt);
	}
	int query(int rt, int l, int r, int L, int R) {
		if (L > r || R < l) return inf;
		if (L <= l && r <= R) return mn[rt];
		return max(tag[rt], min(query(ls, l, mid, L, R), query(rs, mid + 1, r, L, R)));
	}
	#undef ls
	#undef rs
	#undef mid
} tr;

int main() {
	scanf("%d%d%d", &n, &vx, &vy);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			scanf("%d", &a[i][j]);
	if (vx < 0) {
		vx = -vx;
		for (int i = 1; i < n - i + 1; ++i)
			for (int j = 1; j <= n; ++j)
				swap(a[i][j], a[n - i + 1][j]);
	}
	if (vy < 0) {
		vy = -vy;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j < n - j + 1; ++j)
				swap(a[i][j], a[i][n - j + 1]);
	}
	if (vx == 0) {
		swap(vx, vy);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j < i; ++j)
				swap(a[i][j], a[j][i]);
	}

	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			b[++m] = vx * j - vy * i;
	sort(b + 1, b + m + 1);
	int mm = m; m = 0;
	for (int i = 1; i <= mm; ++i)
		if (!m || b[i] != b[m]) b[++m] = b[i];
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			pos[i][j] = lower_bound(b + 1, b + m + 1, vx * j - vy * i) - b;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			int L = pos[i][j - 1], R = pos[i - 1][j] - 1;
			ans += max(0, a[i][j] - tr.query(1, 1, m, L, R));
			tr.update(1, 1, m, L, R, a[i][j]);
		}
	printf("%lld\n", ans);
	return 0;
}