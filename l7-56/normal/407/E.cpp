#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <ll, ll> pii;
typedef vector <ll> vi;
#define fir first
#define sec second
template <typename __Tp> void read(__Tp &x) {
	int f = x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}
void read(char &ch) { for (ch = getchar(); isspace(ch); ch = getchar()); }
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &... y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
void write(const char *s) { for (; *s; ++s) putchar(*s); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ... y) { write(x), write(y...); }

const ll maxn = 2e5 + 10, inf = 1e9;
ll n, m, k, d, a[maxn];
vi B, pos[maxn];
pii ans = {1, 1};

struct SegTree {
	ll mn[maxn << 2], add[maxn << 2];
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) >> 1)
	void push_up(ll rt) { mn[rt] = min(mn[ls], mn[rs]); }
	void build(ll rt, ll l, ll r) {
		add[rt] = 0;
		if (l == r) return mn[rt] = l, void();
		build(ls, l, mid), build(rs, mid + 1, r), push_up(rt);
	}
	void tag(ll rt, ll v) { add[rt] += v, mn[rt] += v; }
	void push_down(ll rt) { if (add[rt]) tag(ls, add[rt]), tag(rs, add[rt]), add[rt] = 0; }
	void ADD(ll rt, ll l, ll r, ll L, ll R, ll v) {
		if (L > r || R < l) return;
		if (L <= l && r <= R) return tag(rt, v);
		push_down(rt), ADD(ls, l, mid, L, R, v), ADD(rs, mid + 1, r, L, R, v), push_up(rt);
	}
	ll query_pos(ll rt, ll l, ll r, ll v) {
		if (mn[rt] > v) return inf;
		if (l == r) return l;
		push_down(rt);
		if (mn[ls] <= v) return query_pos(ls, l, mid, v);
		return query_pos(rs, mid + 1, r, v);
	}
	#undef ls
	#undef rs
	#undef mid
}tr;

ll stn[maxn], tpn, stx[maxn], tpx;

int main() {
	read(n, k, d);
	for (ll i = 1; i <= n; ++i) read(a[i]);
	if (d == 0) {
		for (ll l = 1, r; l <= n; l = r) {
			for (r = l; r <= n && a[r] == a[l]; ++r);
			if (r - l - 1 > ans.sec - ans.fir) ans = make_pair(l, r - 1);
		}
		write(ans.fir, ' ', ans.sec, '\n');
		return 0;
	}

	for (ll l = 1, r; l <= n; l = r) {
		for (r = l; r <= n && (a[l] - a[r]) % d == 0; ++r);
		ll len = r - l, b = (a[l] % d + d) % d;
		tr.build(1, 1, len);
		for (ll i = l; i < r; ++i) a[i] = (a[i] - b) / d;

		map <ll, ll> lst;
		ll *v = a + l - 1;
		lst[v[1]] = 1, stn[tpn = 1] = 1, stx[tpx = 1] = 1;
		for (ll i = 2; i <= len; ++i) {
			while (tpn && v[stn[tpn]] > v[i])
				tr.ADD(1, 1, len, stn[tpn - 1] + 1, stn[tpn], v[stn[tpn]] - v[i]), --tpn;
			while (tpx && v[stx[tpx]] < v[i])
				tr.ADD(1, 1, len, stx[tpx - 1] + 1, stx[tpx], v[i] - v[stx[tpx]]), --tpx;
			stn[++tpn] = stx[++tpx] = i;

			if (lst[v[i]]) tr.ADD(1, 1, len, 1, lst[v[i]], inf);
			lst[v[i]] = i;
			ll j = tr.query_pos(1, 1, len, k + i);
			pii p = make_pair(l + j - 1, l + i - 1);
			if (p.sec - p.fir > ans.sec - ans.fir ||
				(p.sec - p.fir == ans.sec - ans.fir && p.fir < ans.fir)) ans = p;
		}
	}
	write(ans.fir, ' ', ans.sec, '\n');
	return 0;
}