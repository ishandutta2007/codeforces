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

const int maxn = 2e5 + 10, mod = 998244353;
int n, m, a[maxn], p[maxn], cntp, mul[1024], popcnt[1024];
void work() {
	read(n, m);
	for (int i = 1; i <= n; ++i) read(a[i]);
	for (int i = 2; i <= n; ++i) if (a[i - 1] % a[i]) return write("0\n");
	int t = a[1];
	cntp = 0;
	for (int i = 2; (ll) i * i <= t; ++i)
		if (t % i == 0) {
			while (t % i == 0) t /= i;
			p[cntp++] = i;
		}
	if (t > 1) p[cntp++] = t;
	for (int s = 0; s < (1 << cntp); ++s) {
		popcnt[s] = popcnt[s & (s - 1)] + ((s & -s) > 0);
		mul[s] = 1;
		for (int i = 0; i < cntp; ++i) if ((s >> i) & 1) mul[s] *= p[i];
	}
	int ans = 1;
	for (int i = 2; i <= n; ++i) {
		if (a[i] == a[i - 1]) { ans = (ll) ans * (m / a[i]) % mod; continue; }
		int lim = m / a[i], v = a[i - 1] / a[i], res = 0, vs = 0;
		for (int j = 0; j < cntp; ++j) if (v % p[j] == 0) vs |= (1 << j);
		for (int s = vs; ; s = (s - 1) & vs) {
			res += (popcnt[s] & 1 ? -1 : 1) * lim / mul[s];
			if (!s) break;
		}
		ans = (ll) ans * res % mod;
	}
	write(ans, '\n');
}

int main() {
	int T; read(T);
	while (T--) work();
	return 0;
}