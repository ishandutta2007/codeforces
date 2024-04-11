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

const ll maxn = 2e6 + 10, N = 1 << 20;
ll n,k,b[maxn],ans[maxn];
bool check(ll n, ll m) {
	if (m > n) return 0;
	if (n == 0) return 1;
	if (m <= 0) return 0;
	return ((n - 1) & (m - 1)) == (m - 1);
}

int main() {
	read(n), read(k);
	for (ll i = 1; i <= n; ++i) read(b[i]);
	for (ll l = 1; l <= n; ++l) {
		ll val = 0;
		for (ll r = l; r <= n; ++r) {
			if (r != l && b[r] > 20) break;
			if (r == l) val = b[r];
			else val *= (1ll << b[r]);
			if (val >= N) break;
			if (check(n + l - r - 3 + (l == 1) + (r == n), k - (l != 1) - (r != n))) ans[val] ^= 1;
		}
	}
	ll len = N - 1;
	while (len > 0 && !ans[len]) --len;
	while (len >= 0) write(ans[len]), --len;
	write('\n');
	return 0;
}