#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

struct pll {
	ll x, y;
	friend pll operator + (pll a, pll b) { return {a.x + b.x, a.y + b.y}; }
	friend bool operator < (pll a, pll b) {
		if (a.x != b.x) return a.x < b.x;
		return a.y < b.y;
	}
	friend pll & operator += (pll &a, pll b) { return a = a + b; }
};
const pll zero = {0, 0};
const ll maxn = 1e5 + 10, inf = 6e9;
ll n, k, m, a[maxn], s[maxn], mns[maxn], rk[maxn];
pll b[maxn];

struct ST {
	int mn[maxn][20], lg2[maxn];
	void build() {
		for (int i = 0; i <= n; ++i) mn[i][0] = b[i].y;
		for (int i = 2; i <= n + 1; ++i) lg2[i] = lg2[i >> 1] + 1;
		for (int j = 1; j < 20; ++j)
			for (int i = 0; i + (1 << j) - 1 <= n; ++i)
				mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
	}
	int query(int l, int r) {
		if (l > r) return -1;
		int i = lg2[r - l + 1];
		return min(mn[l][i], mn[r - (1 << i) + 1][i]);
	}
} st;

struct BIT {
	pll c[maxn];
	void clr() { for (int i = 1; i <= n + 1; ++i) c[i] = zero; }
	void add(int pos, pll val) { for (++pos; pos <= n + 1; pos += pos & (-pos)) c[pos] += val; }
	pll ask(int pos) {
		pll res = zero;
		for (++pos; pos > 0; pos &= pos - 1) res += c[pos];
		return res;
	}
} tr1;

struct SegTree {
	pll mx[maxn << 2][2], add[maxn << 2];
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) >> 1)
	void push_up(int rt) {
		mx[rt][0] = max(mx[ls][0], mx[rs][0]);
		mx[rt][1] = max(mx[ls][1], mx[rs][1]);
	}
	void build(int rt, int l, int r) {
		mx[rt][0] = mx[rt][1] = (pll) {-inf, 0}, add[rt] = zero;
		if (l >= r) return;
		build(ls, l, mid), build(rs, mid + 1, r);
	}
	void tag(int rt, pll val) { add[rt] += val, mx[rt][0] += val, mx[rt][1] += val; }
	void push_down(int rt) { tag(ls, add[rt]), tag(rs, add[rt]), add[rt] = zero; }
	void update(int rt, int l, int r, int pos, pll val) {
		if (l == r) {
			mx[rt][0] = mx[rt][1] = val;
			if (l > 0) mx[rt][1].x -= mns[l - 1];
			return;
		}
		push_down(rt); pos <= mid ? update(ls, l, mid, pos, val) : update(rs, mid + 1, r, pos, val); push_up(rt);
	}
	void ADD(int rt, int l, int r, int L, int R, pll val) {
		if (L > R || L > r || R < l) return;
		if (L <= l && r <= R) return tag(rt, val);
		push_down(rt), ADD(ls, l, mid, L, R, val), ADD(rs, mid + 1, r, L, R, val), push_up(rt);
	}
	pll query(int rt, int l, int r, int L, int R, int c) {
		if (L > R || L > r || R < l) return {-inf, 0};
		if (L <= l && r <= R) return mx[rt][c];
		return push_down(rt), max(query(ls, l, mid, L, R, c), query(rs, mid + 1, r, L, R, c));
	}
	#undef ls
	#undef rs
	#undef mid
} tr2;

pll work(ll dlt) {
	tr1.clr();
	tr2.build(1, 0, n);
	tr2.update(1, 0, n, 0, zero);
	pll tmp = zero;
	for (int i = 1; i <= n; ++i) {
		tr1.add(rk[i - 1], {s[i - 1], 1});
		ll pos = lower_bound(b, b + n + 1, (pll) {s[i] - dlt, inf}) - b - 1;
		pll res = tr1.ask(pos); res.x = res.y * (s[i] - dlt) - res.x;
		tmp += res;
		tr2.ADD(1, 0, n, 0, i, res);
		if (res.y == i) continue;

		int mnp = res.y ? st.query(0, pos) : i;
		if (!mnp && s[i] >= dlt) --mnp;
		tmp = max(tmp, tr2.query(1, 0, n, mnp + 1, i, 0));
		if (!res.y) tr2.update(1, 0, n, i, tmp), tmp = {-inf, 0};

		res = tr2.query(1, 0, n, 0, mnp, 1);
		res.x += s[i] - dlt, res.y++;
		tmp = max(tmp, res);
	}
	return tmp;
}

int main() {
	scanf("%lld%lld", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]), s[i] = s[i - 1] + a[i], mns[i] = min(mns[i - 1], s[i]), b[i] = {s[i], i};
	sort(b, b + n + 1);
	for (int i = 0; i <= n; ++i) rk[b[i].y] = i;
	for (int i = 1; i <= n; ++i)
		if (s[i] == s[i - 1]) rk[i] = min(rk[i], rk[i - 1]);
	for (int i = n - 1; i >= 0; --i)
		if (s[i] == s[i + 1]) rk[i] = min(rk[i], rk[i + 1]);
	st.build();

	ll l = -inf, r = inf, mid, ans = 0;
	while (l <= r) {
		mid = (l + r) / 2; pll res = work(mid);
		if (res.y >= k) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%lld\n", ans * k + work(ans).x);
	return 0;
}