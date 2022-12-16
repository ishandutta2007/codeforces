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

const int maxn = 2e5 + 10;
int a[maxn], n, m, f[maxn];
void work() {
	read(n, m);
	vector <int> b;
	vector < vector <int> > pos(n + 1);
	for (int i = 1; i <= n; ++i)
		read(a[i]), b.push_back(a[i]);
	sort(b.begin(), b.end()), b.erase(unique(b.begin(), b.end()), b.end());
	for (int i = 1; i <= n; ++i)
		a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1,
		pos[a[i]].push_back(i), f[i] = i;
	for (int i = 1; i <= m; ++i) {
		int l, r; read(l, r);
		f[l] = max(f[l], r);
	}
	for (int i = 2; i <= n; ++i) f[i] = max(f[i], f[i - 1]);

	int L = n + 1, R = 0;
	multiset <int> s;
	vector <int> c(n + 10, 0);
	for (int i = 1; i <= n; ++i) {
		int pl = lower_bound(pos[a[i]].begin(), pos[a[i]].end(), i) - pos[a[i]].begin();
		int pr = upper_bound(pos[a[i]].begin(), pos[a[i]].end(), f[i]) - pos[a[i]].begin() - 1;
		if (pl == pr) continue;
		L = min(L, pos[a[i]][pl + 1]), R = max(R, i);
		s.insert(i), c[i] = pos[a[i]][pr];
	}
	s.insert(R);

	int ans = n;
	for (int i = 1; i <= n; ++i) {
		if (i <= L) ans = min(ans, max(0, *--s.end() - i + 1));
		if (c[i]) s.erase(s.find(i)), s.insert(c[i]);
	}
	write(ans, '\n');
}

int main() {
	int T; read(T);
	while (T--) work();
	return 0;
}