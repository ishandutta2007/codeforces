#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
template <typename __Tp> void read(__Tp &x) {
	ll f = x = 0; char ch = getchar();
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

const int maxn = 1e5 + 10, T = 400, maxp = maxn / T + 10;
ll n, p, q, s[maxn], m[maxn], c[maxn];
ll lb[maxn], rb[maxn], bel[maxn], val[maxp][maxn], lst[maxn], tag[maxn];

void prework() {
	for (ll i = 1; i <= n; ++i) bel[i] = (i - 1) / T + 1;
	p = bel[n];
	for (ll i = 1; i <= p; ++i) {
		lb[i] = rb[i - 1] + 1, rb[i] = min(i * T, n);

		for (ll j = lb[i]; j <= rb[i]; ++j)
			if (c[j]) val[i][1] += c[j], val[i][m[j] / c[j] + 1] -= c[j];
		for (ll j = 1; j <= 100000; ++j) val[i][j] += val[i][j - 1];
		for (ll j = lb[i]; j <= rb[i]; ++j)
			if (c[j]) val[i][m[j] / c[j] + 1] += m[j] % c[j];
		for (ll j = 1; j <= 100000; ++j) val[i][j] += val[i][j - 1];
	}
}

ll solve(ll x, ll l, ll r, ll t) {
	ll res = 0;
	if (!tag[x]) {
		for (ll i = l; i <= r; ++i)
			res += min(m[i], s[i] + c[i] * (t - lst[i])), s[i] = 0, lst[i] = t;
		return res;
	}
	tag[x] = 0;
	ll lt = lst[lb[x]];
	for (ll i = lb[x]; i <= rb[x]; ++i)
		if (l <= i && i <= r)
			res += min(m[i], c[i] * (t - lt)), s[i] = 0, lst[i] = t;
		else s[i] = 0, lst[i] = lt;
	return res;
}

ll solve(ll l, ll r, ll t) {
	ll x = bel[l], y = bel[r];
	if (x == y) return solve(x, l, r, t);
	ll res = solve(x, l, rb[x], t) + solve(y, lb[y], r, t);
	for (++x; x < y; ++x) {
		if (tag[x]) res += val[x][min(100000ll, t - lst[lb[x]])], lst[lb[x]] = t;
		else {
			for (ll i = lb[x]; i <= rb[x]; ++i)
				res += min(m[i], s[i] + c[i] * (t - lst[i]));
			lst[lb[x]] = t, tag[x] = 1;
		}
	}
	return res;
}

int main() {
	read(n);
	for (int i = 1; i <= n; ++i) read(s[i], m[i], c[i]);
	prework();
	read(q);
	while (q--) {
		int t, l, r; read(t, l, r);
		write(solve(l, r, t), '\n');
	}
	return 0;
}