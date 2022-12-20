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

#define in(x, y) (((x) >> (y)) & 1)
#define bit(x) (1 << (x))
int n, m, q, e[20], anc[20];
ll f[1 << 13][20];
vector <pii> vec[20];

int main() {
	read(n, m, q);
	for (int i = 1; i <= m; ++i) {
		int u, v; read(u, v);
		e[u] |= bit(v - 1), e[v] |= bit(u - 1);
	}
	for (int i = 1; i <= q; ++i) {
		int a, b, c; read(a, b, c);
		vec[c].push_back({a, b});
		anc[a] |= bit(c - 1), anc[b] |= bit(c - 1);
	}
	for (int i = 1; i <= n; ++i) f[bit(i - 1)][i] = 1;
	for (int s = 1; s < (1 << n); ++s) {
		for (int i = 1; i <= n; ++i) {
			int ss = s ^ bit(i - 1);
			if (!in(s, i - 1) || (ss & anc[i])) continue;
			int lbt = ss & -ss;
			for (int t = ss; t; t = (t - 1) & ss) {
				if (!(t & lbt)) continue;
				auto check = [&] () {
					for (int j = 1; j <= n; ++j) {
						if (in(t, j - 1) && ((e[j] | anc[j]) & (ss ^ t))) return 0;
						if (in(ss ^ t, j - 1) && (anc[j] & t)) return 0;
					}
					for (pii p : vec[i]) if (in(t, p.fir - 1) && in(t, p.sec - 1)) return 0;
					return 1;
				};
				if (!check()) continue;
				int sj = e[i] & t;
				if (sj & (sj - 1)) continue;
				if (!sj) sj = t;
				for (int j = 1; j <= n; ++j) {
					if (!in(sj, j - 1)) continue;
					f[s][i] += f[t][j] * f[s ^ t][i];
				}
			}
			// printf("%d %d %lld\n", s, i, f[s][i]);
		}
	}
	write(f[bit(n) - 1][1], '\n');
	return 0;
}