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

const int maxn = 2e5 + 10;
int n,a[maxn],m,f[maxn],g[maxn];
struct BIT {
	int c[maxn];
	void clr() { memset(c, 0, sizeof c); }
	void upd(int pos, int val) { for (; pos <= m; pos += pos & (-pos)) c[pos] = max(c[pos], val); }
	int ask(int pos) {
		int res = 0;
		for (; pos > 0; pos &= pos - 1) res = max(res, c[pos]);
		return res;
	}
}T;
vector <int> A;

int main() {
	read(n);
	for (int i = 1; i <= n; ++i) read(a[i]), a[i] -= i, A.push_back(a[i]);
	sort(A.begin(), A.end());
	A.erase(unique(A.begin(), A.end()), A.end());
	m = A.size();
	for(int i = 1; i <= n; ++i) a[i] = lower_bound(A.begin(), A.end(), a[i]) - A.begin() + 1;

	int ans = 1;
	for (int i = 1; i <= n; ++i) f[i] = T.ask(a[i]) + 1, T.upd(a[i], f[i]), ans = max(ans, f[i] + 1);
	T.clr();
	for (int i = n; i >= 1; --i) g[i] = T.ask(m - a[i] + 1) + 1, T.upd(m - a[i] + 1, g[i]), ans = max(ans, g[i] + 1);
	T.clr();
	for (int i = 2; i < n; ++i) {
		T.upd(a[i - 1], f[i - 1]);
		int pos = upper_bound(A.begin(), A.end(), A[a[i + 1] - 1] + 1) - A.begin();
		ans = max(ans, T.ask(min(pos, m)) + g[i + 1] + 1);
	}
	write(max(0, n - ans), '\n');
	return 0;
}