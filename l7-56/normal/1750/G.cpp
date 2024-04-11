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

const int maxn = 2010;
int n, mod, a[maxn], C[maxn][maxn], f[maxn][maxn], vis[maxn], ans[maxn];

int main() {
	read(n, mod);
	for (int i = 1; i <= n; ++i) read(a[i]);

	C[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	}

	f[0][0] = 1;
	for (int i = 1; i <= n; ++i) f[i][0] = (ll) f[i - 1][0] * i % mod;
	for (int j = 1; j <= n; ++j)
		for (int i = 1; i <= n; ++i)
			f[i][j] = (f[i][j - 1] + mod - f[i - 1][j - 1]) % mod;
	for (int i = 1, cnt = n - 1, cnt2 = 0; i <= n; ++i) {
		map <pii, int> mp;
		for (int x = 1; x < a[i]; ++x) if (!vis[x])
			mp[{cnt2 + (i > 1 && x == a[i - 1] + 1), cnt - (x > 1 && !vis[x - 1])}]++;
		for (auto p : mp) {
			int k1 = p.fir.fir, c = p.fir.sec, w = p.sec;
			for (int k = 0; k <= n - i && k <= c; ++k)
				ans[k + k1] = (ans[k + k1] + (ll) C[c][k] * f[n - i - k][c - k] % mod * w % mod) % mod;
		}
		vis[a[i]] = 1;
		if (a[i] > 1 && !vis[a[i] - 1]) cnt--;
		if (a[i] < n && !vis[a[i] + 1]) cnt--;
		if (i > 1 && a[i] == a[i - 1] + 1) ++cnt2;
	}
	for (int i = 1; i <= n; ++i)
		printf("%d%c", ans[n - i], " \n"[i == n]);
	return 0;
}