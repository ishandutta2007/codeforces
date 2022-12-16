#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
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

const int maxn = 5e4 + 10, maxa = 1e6 + 10;
int n,m,a[maxn],s[maxa],ans[maxn],val[maxn];
vector <pii> v[maxn];

int main() {
	for (int i = 1; i <= 1000000; ++i) s[i] = s[i - 1] ^ i;
	read(n, m);
	for (int i = 1; i <= n; ++i) read(a[i]);
	for (int i = 1; i <= m; ++i) {
		int l, r; read(l, r);
		v[r].push_back({l, i});
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j >= 1; --j)
			val[j] = max(val[j], max(val[j + 1], s[min(a[i], a[j]) - 1] ^ s[max(a[i], a[j])]));
		for (pii p : v[i]) ans[p.second] = val[p.first];
	}
	for (int i = 1; i <= m; ++i) write(ans[i], '\n');
	return 0;
}