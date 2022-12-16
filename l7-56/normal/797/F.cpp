#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <ll, ll> pll;
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

const int maxn = 5010;
ll n,m,f[maxn],g[maxn],a[maxn],s[maxn];
pll b[maxn];

ll q[maxn],hd,tl;
void solve(ll i) {
	memset(f, 0x3f, sizeof f);
	q[hd = tl = 1] = 0;
	f[0] = 0;
	#define val(k) (g[k] - s[k])
	for (ll j = 1; j <= n; ++j) {
		s[j] = s[j - 1] + abs(a[j] - b[i].first);
		while (hd <= tl && val(q[tl]) >= val(j)) --tl;
		q[++tl] = j;
		while (hd <= tl && q[hd] < j - b[i].second) ++hd;
		f[j] = val(q[hd]) + s[j];
	}
}

int main() {
	read(n, m);
	for (ll i = 1; i <= n; ++i) read(a[i]);
	ll tot = 0;
	for (ll i = 1; i <= m; ++i) read(b[i].first, b[i].second), tot += b[i].second;
	if (tot < n) return write(-1, '\n'), 0;
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	memset(g, 0x3f, sizeof g);
	g[0] = 0;
	for (ll i = 1; i <= m; ++i) {
		solve(i);
		for (ll j = 0; j <= n; ++j) g[j] = f[j];
	}
	write(g[n], '\n');
	return 0;
}