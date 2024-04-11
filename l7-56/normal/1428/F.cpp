#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vl;
#define fir first
#define sec second

const int maxn = 5e5 + 10;
int n;
char s[maxn];
struct SegTree {
	ll sum[maxn << 2], mx[maxn << 2], hastag[maxn << 2];
	pll cov[maxn << 2];
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) >> 1)
	void push_up(int rt) { sum[rt] = sum[ls] + sum[rs], mx[rt] = max(mx[ls], mx[rs]); }
	void tag(int rt, int l, int r, pll p) {
		cov[rt] = p, hastag[rt] = 1;
		sum[rt] = (r - l + 1) * ((l + r) * p.fir + 2 * p.sec) / 2;
		mx[rt] = p.fir * l + p.sec;
	}
	void push_down(int rt, int l, int r) { if (hastag[rt]) tag(ls, l, mid, cov[rt]), tag(rs, mid + 1, r, cov[rt]), hastag[rt] = 0; }
	void update(int rt, int l, int r, int L, int R, pll p) {
		if (L > r || R < l || L > R) return;
		if (L <= l && r <= R) return tag(rt, l, r, p);
		push_down(rt, l, r), update(ls, l, mid, L, R, p), update(rs, mid + 1, r, L, R, p), push_up(rt);
	}
	int query(int rt, int l, int r, int x) {
		if (mx[rt] <= x) return l - 1;
		if (l == r) return l;
		push_down(rt, l, r);
		if (mx[rs] > x) return query(rs, mid + 1, r, x);
		return query(ls, l, mid, x);
	}
	#undef ls
	#undef rs
	#undef mid
} tr;

int main() {
	scanf("%d%s", &n, s + 1);
	ll ans = 0, len = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '1') ++len;
		else len = 0;
		int pos = tr.query(1, 1, n, len);
		tr.update(1, 1, n, pos + 1, i - len, {0, len});
		tr.update(1, 1, n, i - len + 1, i, {-1, i + 1});
		ans += tr.sum[1];
	}
	printf("%lld\n", ans);
	return 0;
}