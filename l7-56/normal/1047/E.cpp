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

ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
const int maxn = 1e6 + 10, P = 1e6, mod = 1e9 + 7, inv2 = 5e8 + 4;
#define inc(x, y) ((x) = ((x) + (y)) % mod)
ll n, a[maxn], fa[maxn], s[maxn], S, f[maxn], cnt[maxn], cnt2[maxn];

int main() {
	read(n);
	for (int i = 1; i <= n; ++i) read(a[i]), s[i] = a[i];
	for (int i = 2; i <= n; ++i) read(fa[i]);
	for (int i = n; i > 1; --i) s[fa[i]] += s[i];
	S = s[1];
	for (int i = 1; i <= n; ++i) {
		ll res = S / gcd(s[i], S);
		if (res <= P) cnt[res]++;
	}
	for (int i = 1; i <= P; ++i)
		for (int j = i; j <= P; j += i)
			cnt2[j] += cnt[i];
	int ans = 1;
	for (int i = 2; i <= P; ++i) {
		if (S % i || cnt2[i] != i) continue;
		inc(f[i], 1), inc(ans, f[i]);
		for (int j = i * 2; j <= P; j += i) inc(f[j], f[i]);
	}
	write(ans, '\n');
	return 0;
}