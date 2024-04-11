#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
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

const ll maxn = 5e5 + 10;
ll n,a[maxn],b[maxn],ans;
struct SegTree {
	ll rt[maxn * 20], ls[maxn * 20], rs[maxn * 20], cnt[maxn * 20], sum[maxn * 20], tot;
	#define mid ((l + r) >> 1)
	void push_up(ll o) { cnt[o] = cnt[ls[o]] + cnt[rs[o]], sum[o] = sum[ls[o]] + sum[rs[o]]; }
	void update(ll &o, ll l, ll r, ll pos) {
		if (!o) o = ++tot;
		if (l == r) return cnt[o] = 1, sum[o] = pos, void();
		pos <= mid ? update(ls[o], l, mid, pos) : update(rs[o], mid + 1, r, pos); push_up(o);
	}
	ll merge(ll p, ll q) {
		if (!p || !q) return p + q;
		ans -= sum[ls[p]] * cnt[rs[p]] + sum[ls[q]] * cnt[rs[q]];
		ls[p] = merge(ls[p], ls[q]), rs[p] = merge(rs[p], rs[q]);
		return ans += sum[ls[p]] * cnt[rs[p]], cnt[p] += cnt[q], sum[p] += sum[q], p;
	}
}tr;
ll fa[maxn],rgt[maxn];
ll get(ll x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }
void merge(ll x, ll y) {
	x = get(x), y = get(y);
	fa[y] = x, ans -= x * tr.sum[tr.rt[x]] + y * tr.sum[tr.rt[y]];
	tr.rt[x] = tr.merge(tr.rt[x], tr.rt[y]), ans += x * tr.sum[tr.rt[x]];
	rgt[x] = rgt[y];
}

int main() {
	read(n);
	for (ll i = 1; i <= 400000; ++i) fa[i] = rgt[i] = i;
	for (ll i = 1; i <= n; ++i) {
		read(a[i], b[i]);
		ll x = tr.rt[a[i]] ? rgt[get(a[i])] + 1 : a[i];
		ans += (x - a[i]) * b[i];
		tr.update(tr.rt[x], 1, n, b[i]);
		if (tr.rt[x - 1]) merge(x - 1, x);
		if (tr.rt[x + 1]) merge(x, x + 1);
		write(ans, '\n');
	}
	return 0;
}