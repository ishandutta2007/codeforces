#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <typename __Tp> void read(__Tp &x) {
	char ch = getchar(); x = 0;
	for (; !isdigit(ch); ch = getchar());
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
}

const int maxn = 4010, maxm = 810, inf = 1e9;
int s[maxn][maxn],n,m,f[maxn][maxm],p[maxn][maxm];

int w(int l, int r) { return s[r][r] - s[l - 1][r] - s[r][l - 1] + s[l - 1][l - 1]; }

int main() {
	read(n), read(m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			read(s[i][j]), s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
	for (int i = 1; i <= n; ++i) f[i][1] = w(1, i), p[i][1] = 0;
	for (int j = 2; j <= m; ++j){
		p[n + 1][j] = n - 1;
		for (int i = n; i >= 1; --i) {
			f[i][j] = inf;
			for (int k = p[i][j - 1]; k <= p[i + 1][j]; ++k)
				if (f[i][j] > f[k][j - 1] + w(k + 1, i)) {
					f[i][j] = f[k][j - 1] + w(k + 1, i);
					p[i][j] = k;
				}
		}
		// for (int i = 1; i <= n; ++i)
		// 	printf("%d%c", f[i][j], " \n"[i == n]);
	}
	printf("%d\n", f[n][m] / 2);
	return 0;
}