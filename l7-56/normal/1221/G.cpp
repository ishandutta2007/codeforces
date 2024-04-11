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

const int maxn = 50;
int n, m, mp[maxn][maxn], vis[maxn], siz, col[maxn], flg = 1, cnt1, cnt2;
void dfs(int u) {
	++siz;
	for (int v = 1; v <= n; ++v)
		if (mp[u][v]) {
			if (!vis[v]) vis[v] = 3 - vis[u], dfs(v);
			else if (vis[v] + vis[u] != 3) flg = 0;
		}
}

ll val[1 << 20], ans;

int main() {
	read(n, m);
	for (int i = 1; i <= m; ++i) {
		int x, y; read(x, y);
		mp[x][y] = mp[y][x] = 1;
	}
	if (m < 3) return printf("0\n"), 0;
	for (int i = 1; i <= n; ++i) if (!vis[i]) {
		vis[i] = 1, siz = 0, dfs(i);
		cnt1++, cnt2 += (siz == 1);
	}
	ans = (1ll << n) - (1ll << cnt1) + (1ll << (cnt2 + 1)) + (1ll << cnt1) * flg;
	int t = n / 2;
	for (int s = 0; s < (1 << t); ++s) {
		for (int i = 1; i <= t; ++i)
			if ((s >> (i - 1)) & 1)
				for (int j = 1; j <= t; ++j)
					if (mp[i][j] && ((s >> (j - 1)) & 1)) goto done1;
		val[s]++;
		done1 : ;
	}
	for (int i = 1; i <= t; ++i)
		for (int s = 0; s < (1 << t); ++s)
			if ((s >> (i - 1)) & 1) val[s] += val[s ^ (1 << (i - 1))];
	for (int s = 0; s < (1 << (n - t)); ++s) {
		int tos = (1 << t) - 1;
		for (int i = t + 1; i <= n; ++i)
			if ((s >> (i - t - 1)) & 1) {
				for (int j = 1; j <= t; ++j)
					if (mp[i][j]) tos &= ~(1 << (j - 1));
				for (int j = t + 1; j <= n; ++j)
					if (mp[i][j] && ((s >> (j - t - 1)) & 1)) goto done2;
			}
		ans -= 2 * val[tos];
		done2 : ;
	}
	write(ans, '\n');
	return 0;
}