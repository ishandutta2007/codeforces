#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
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

const int maxn = 1e6 + 10, A = 1e6;
int n, lx[maxn], rx[maxn], ln[maxn], rn[maxn], stk[maxn], tp, a[maxn], p[maxn];
vi g[maxn], pos[maxn];

void work() {
	read(n);
	for (int i = 1; i <= n; ++i) read(a[i]);
	for (int i = 1; i <= n; ++i) pos[a[i]].push_back(i);
	stk[tp = 0] = 0;
	for (int i = 1; i <= n; ++i) {
		while (tp && a[stk[tp]] <= a[i]) rx[stk[tp--]] = i;
		lx[i] = stk[tp], stk[++tp] = i;
	}
	while (tp) rx[stk[tp--]] = n + 1;
	for (int i = 1; i <= n; ++i) {
		while (tp && a[stk[tp]] >= a[i]) --tp;
		ln[i] = stk[tp], stk[++tp] = i;
	}
	stk[tp = 0] = n + 1;
	for (int i = n; i >= 1; --i) {
		while (tp && a[stk[tp]] >= a[i]) --tp;
		rn[i] = stk[tp], stk[++tp] = i;
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int x : g[a[i]]) {
			if (p[x]) {
				int j = pos[x][p[x] - 1];
				ans += (ll) max(0, j - max(lx[i], ln[j])) * max(0, min(rx[i], rn[j]) - i);
			}
			if (p[x] < (int) pos[x].size()) {
				int j = pos[x][p[x]], l = ln[j];
				if (p[x]) l = max(l, pos[x][p[x] - 1]);
				ans += (ll) max(0, i - max(lx[i], l)) * max(0, min(rx[i], rn[j]) - j);
			}
		}
		++p[a[i]];
	}
	write(ans, '\n');
	for (int i = 1; i <= n; ++i) pos[a[i]].resize(0), p[a[i]] = 0;
}

int main() {
	for (int i = 1; i <= A; ++i)
		for (int j = i; j <= A; j += i) g[j].push_back(i);
	int T; read(T);
	while (T--) work();
	return 0;
}