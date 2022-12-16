#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vp;
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

const int maxn = 110, inf = 1e9;
int n;
char s[maxn][maxn][maxn];
void work() {
	read(n);
	function <int(vi &, int)> get = [&] (vi &fa, int x) { return x == fa[x] ? x : fa[x] = get(fa, fa[x]); };
	auto merge = [&] (vi &fa, int x, int y) -> void { fa[get(fa, x)] = get(fa, y); };
	vi fe(n * n + 10);
	iota(fe.begin(), fe.end(), 0);
	#define num(i, j) (((i) - 1) * n + (j))
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < i; ++j)
			merge(fe, num(i, j), num(j, i));
	for (int i = 1; i <= n; ++i) {
		for (int k = 1; k <= n; ++k) s[i][i][k] = '1';
		for (int j = i + 1; j <= n; ++j) {
			scanf("%s", s[i][j] + 1);
			for (int k = 1; k <= n; ++k) {
				s[j][i][k] = s[i][j][k];
				if (s[i][j][k] == '1')
					merge(fe, num(i, k), num(j, k));
			}
		}
	}
	vector <vp> ae(n * n + 10);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			ae[get(fe, num(i, j))].push_back({i, j});
	auto check = [&](vp &e) -> int {
		if ((int) e.size() != n - 1) return 0;
		vi fn(n + 10);
		iota(fn.begin(), fn.end(), 0);
		for (pii p : e) merge(fn, p.fir, p.sec);
		for (int i = 2; i <= n; ++i)
			if (get(fn, i) != get(fn, 1)) return 0;
		vector <vi> d(n + 10, vi(n + 10, inf));
		for (pii p : e) d[p.fir][p.sec] = d[p.sec][p.fir] = 1;
		for (int i = 1; i <= n; ++i) d[i][i] = 0;
		for (int k = 1; k <= n; ++k)
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				for (int k = 1; k <= n; ++k)
					if ((d[i][k] == d[j][k]) != (s[i][j][k] == '1')) return 0;
		return 1;
	};
	for (int i = 1; i <= n * n; ++i) {
		vp e;
		for (pii p : ae[i]) if (p.fir < p.sec) e.push_back(p);
		if (!check(e)) continue;
		write("Yes\n");
		for (pii p : e) write(p.fir, ' ', p.sec, '\n');
		return;
	}
	write("No\n");
}

int main() {
	int T; read(T);
	while (T--) work();
	return 0;
}