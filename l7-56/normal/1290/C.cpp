#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
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

const int maxn = 1e6 + 10;
int n,k,fa[maxn],siz[maxn][2],ans,bel[maxn][3];
int get(int x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }
void merge(int x, int y) {
	x = get(x), y = get(y);
	if (x == y) return;
	ans -= min(siz[x][0], siz[x][1]) + min(siz[y][0], siz[y][1]);
	fa[y] = x, siz[x][0] += siz[y][0], siz[x][1] += siz[y][1];
	ans += min(siz[x][0], siz[x][1]);
}
char s[maxn];

int main() {
	read(n, k);
	scanf("%s", s + 1);
	for (int i = 1; i <= k; ++i) {
		int l, x; read(l);
		while (l--) read(x), bel[x][++bel[x][0]] = i;
	}
	k++;
	for (int i = 0; i < k + k; ++i) fa[i] = i, siz[i][i >= k] = 1;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '1') merge(bel[i][1], bel[i][2]), merge(bel[i][1] + k, bel[i][2] + k);
		else merge(bel[i][1], bel[i][2] + k), merge(bel[i][1] + k, bel[i][2]);
		int x = get(0);
		write(ans / 2 - min(siz[x][0], siz[x][1]) + siz[x][1], '\n');
	}
	return 0;
}