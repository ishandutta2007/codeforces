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

const int maxn = 2e5 + 10;
int n, a[maxn];
void work() {
	read(n);
	int s = 0;
	for (int i = 1; i <= n; ++i) read(a[i]), s += a[i];
	if (s & 1) return write("-1\n");
	vector <pii> ans;
	for (int i = 1; i <= n;) {
		if (i < n && (ll) s * a[i + 1] > 0) ans.push_back({i, i + 1}), i += 2, s = (s < 0 ? s + 2 : s - 2);
		else ans.push_back({i, i}), ++i;
	}
	write(ans.size(), '\n');
	for (pii p : ans) write(p.fir, ' ', p.sec, '\n');
}

int main() {
	int T; read(T);
	while (T--) work();
	return 0;
}