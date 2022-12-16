#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
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

#define sqr(x) ((x) * (x))
const int maxn = 1e7 + 10, A = 4e6;
ll n, a[maxn], mx[maxn], mn[maxn];

int main() {
	memset(mn, 0x3f, sizeof mn);
	read(n);
	for (ll i = 1; i <= n; ++i) read(a[i]), mx[a[i]] = mn[a[i]] = a[i];
	for (ll i = 1; i <= A; ++i) mx[i] = max(mx[i], mx[i - 1]);
	for (ll i = A; i >= 1; --i) mn[i] = min(mn[i], mn[i + 1]);
	for (ll i = 1; ; ++i) {
		if (sqr(i) + i < a[1]) continue;
		ll up = sqr(i) + i - a[1], dw = max(sqr(i) - a[1], 0ll);
		for (ll j = i; ; ++j) {
			ll l = sqr(j) - dw, r = sqr(j + 1) - up - 1;
			if (l <= r && mx[r] >= l) up = min(up, sqr(j) + j - mx[r]);
			if (dw > up) break;
			l = sqr(j) + j - dw + 1, r = sqr(j + 1) + j + 1 - up;
			if (l <= r && mn[l] <= r) dw = max(dw, sqr(j + 1) - mn[l]);
			if (dw > up) break;
			if (r >= a[n]) break;
		}
		if (dw <= up) return write(dw, '\n'), 0;
	}
	return 0;
}