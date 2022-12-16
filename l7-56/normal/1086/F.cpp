#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef pair <ll, ll> pll;
#define fir first
#define sec second
template <typename __Tp> void read(__Tp &x) {
    int f = 0; x = 0; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
    for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    if (f) x = -x;
}
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &...y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
void write(const char *s) { for (int i = 0; s[i]; ++i) putchar(s[i]); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ...y) { write(x), write(y...); }

const int maxn = 60, mod = 998244353, inv2 = 499122177, inv3 = 332748118, inv6 = 166374059, inf = 1e9;
ll s0(ll n) { return n % mod; }
ll s1(ll n) { return n * (n + 1) % mod * inv2 % mod; }
ll s2(ll n) { return n * (n + 1) % mod * (2 * n + 1) % mod * inv6 % mod; }
ll sum(ll (*func) (ll), ll l, ll r) { return ((*func)(r) + mod - (*func)(l - 1)) % mod; }
ll sf(ll a, ll b, ll c, ll l, ll r) { return (a * sum(s2, l, r) % mod + b * sum(s1, l, r) % mod + c * sum(s0, l, r) % mod) % mod; }
pll a[maxn];
ll n, t;

struct line {
    ll x, sy, ey, c;
    line() { x = sy = ey = 0; }
    line(ll x, ll sy, ll ey, ll c) : x(x), sy(sy), ey(ey), c(c) {}
    friend bool operator < (line a, line b) { return a.x < b.x; }
};
ll Y[1000], m, cnt[1000];
ll calc(ll x) {
    ll res = 0;
    vector <line> vec;
    for (int i = 1; i <= n; ++i)
        vec.emplace_back(a[i].fir - x, a[i].sec - x, a[i].sec + x, 1),
        vec.emplace_back(a[i].fir + x + 1, a[i].sec - x, a[i].sec + x, -1);
    sort(begin(vec), end(vec));

	m = 0;
	for (line p : vec) Y[++m] = p.sy, Y[++m] = p.ey + 1;
	sort(Y + 1, Y + m + 1), m = unique(Y + 1, Y + m + 1) - Y - 1;
	for (int i = 1; i <= m; ++i) cnt[i] = 0;

	ll s = 0, lst = 0;
    for (line p : vec) {
        res += s * (p.x - lst) % mod;
		ll l = lower_bound(Y + 1, Y + m + 1, p.sy) - Y, r = lower_bound(Y + 1, Y + m + 1, p.ey + 1) - Y;
		for (int i = l; i < r; ++i) {
			s -= (!!cnt[i]) * (Y[i + 1] - Y[i]);
			cnt[i] += p.c;
			s += (!!cnt[i]) * (Y[i + 1] - Y[i]);
		}
        lst = p.x;
	}
    res %= mod;
	// printf("%lld %lld\n", x, res);
    return res;
}

ll calc(ll l, ll r) {
	if (r - l + 1 <= 3) {
		ll res = 0;
		for (ll i = l; i <= r; ++i) res += calc(i);
		return res % mod;
	}
	ll x[3] = {l, l + 1, l + 2}, y[3] = {calc(l), calc(l + 1), calc(l + 2)};
	ll a = ((y[2] + y[0] - y[1] * 2) % mod * inv2 % mod + mod) % mod;
	ll b = ((y[1] - y[0] - a * (x[1] + x[0]) % mod) % mod + mod) % mod;
	ll c = ((y[0] - a * x[0] % mod * x[0] % mod - b * x[0] % mod) % mod + mod) % mod;
	return sf(a, b, c, l, r);
}

int main() {
    // freopen("c.in", "r", stdin), freopen("c.out", "w", stdout);
    read(n, t);
    for (int i = 1; i <= n; ++i) read(a[i].fir, a[i].sec);
	if (n == 1)
		return write(4 * t * (t + 1) % mod * (2 * t + 1) % mod * inv3 % mod, '\n'), 0;
	ll ans = calc(t) * t % mod;
	vl pos({t});
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < i; ++j) {
			ll x = (max(abs(a[i].fir - a[j].fir), abs(a[i].sec - a[j].sec)) + 1) >> 1;
			if (x < t) pos.push_back(x);
		}
	sort(begin(pos), end(pos));
	pos.erase(unique(begin(pos), end(pos)), end(pos));
	ll l = 0;
	for (ll r : pos) ans = (ans + mod - calc(l, r - 1)) % mod, l = r;
    write(ans, '\n');
	return 0;
}