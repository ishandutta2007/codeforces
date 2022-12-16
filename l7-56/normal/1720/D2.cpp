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

#define chkmx(x, y) ((x) = max(x, y))
const int maxn = 3e5 + 10, B = 30, maxm = 1.2e7 + 10, inf = 1e9;
struct Trie {
	int tot, trie[maxm][2], mx[maxm][2][2];
	int NEW() {
		++tot;
		trie[tot][0] = trie[tot][1] = 0;
		mx[tot][0][0] = mx[tot][0][1] = mx[tot][1][0] = mx[tot][1][1] = -inf;
		return tot;
	}
	void init() { tot = 0, NEW(); }
	void ins(int i, int a, int f) {
		int nw = 1;
		for (int bit = B; bit >= 0; --bit) {
			int ci = (i >> bit) & 1, ca = (a >> bit) & 1;
			chkmx(mx[nw][ci][ca], f);
			if (!trie[nw][ci ^ ca]) trie[nw][ci ^ ca] = NEW();
			nw = trie[nw][ci ^ ca];
		}
	}
	int ask(int i, int a) {
		int res = 0, nw = 1;
		for (int bit = B; bit >= 0; --bit) {
			int ci = (i >> bit) & 1, ca = (a >> bit) & 1;
			for (int p : {0, 1})
				for (int q : {0, 1})
					if ((q ^ ci) < (p ^ ca)) chkmx(res, mx[nw][p][q]);
			if (!trie[nw][ci ^ ca]) break;
			nw = trie[nw][ci ^ ca];
		}
		return res;
	}
} tr;

int n, a[maxn], f[maxn];
void work() {
	read(n), tr.init();
	for (int i = 0; i < n; ++i) read(a[i]);
	int ans = 1;
	for (int i = 0; i < n; ++i)
		f[i] = tr.ask(i, a[i]) + 1, tr.ins(i, a[i], f[i]), ans = max(ans, f[i]);
	write(ans, '\n');
}

int main() {
	int T; read(T);
	while (T--) work();
	return 0;
}