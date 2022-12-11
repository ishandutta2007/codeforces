// =================================
//   author: memset0
//   date: 2019.07.30 23:55:06
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
#define rep(i, l, r) for (int i = (l), i##ed = (r); i <= i##ed; ++i)
#define for_each(i, a) for (size_t i = 0, i##ed = a.size(); i < i##ed; ++i)
namespace ringo {

template <class T> inline void read(T &x) {
	x = 0; char c = getchar(); bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}
template <class T> inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}
template <class T> inline void print(T x, char c) { print(x), putchar(c); }
template <class T> inline void print(T a, int l, int r, std::string s = "") {
	if (s != "") std::cout << s << ": ";
	for (int i = l; i <= r; i++) print(a[i], " \n"[i == r]);
}

const int N = 55;
char s[N];
int n, a[N][N], f[N][N][N][N];

int main() {
	memset(f, 63, sizeof(f));
	read(n);
    for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		for (int j = 1; j <= n; j++) a[i][j] = s[j - 1] == '#';
	}
    for (int l = 1; l <= n; l++)
        for (int r = 1; l + r <= 2 * n; r++) {
            for (int i = 1, ii = l; ii <= n; i++, ii++) {
                for (int j = 1, jj = r; jj <= n; j++, jj++) {
                    if (l == r) f[i][ii][j][jj] = std::min(l, f[i][ii][j][jj]);
                    if (l == 1 && r == 1 && !a[i][j]) f[i][ii][j][jj] = 0;
                    for (int k = 1; k <=  i - 1; k++) f[k][ii][j][jj] = std::min(f[k][ii][j][jj], f[k][i - 1][j][jj] + f[i][ii][j][jj]);
                    for (int k = ii + 1; k <= n; k++) f[i][k][j][jj]  = std::min(f[i][k][j][jj], f[i][ii][j][jj] + f[ii + 1][k][j][jj]);
                    for (int k = 1; k <=  j - 1; k++) f[i][ii][k][jj] = std::min(f[i][ii][k][jj], f[i][ii][j][jj] + f[i][ii][k][j - 1]);
                    for (int k = jj + 1; k <= n; k++) f[i][ii][j][k]  = std::min(f[i][ii][j][k], f[i][ii][j][jj] + f[i][ii][j + 1][k]);
                }
            }
        }
	print(f[1][n][1][n], '\n');
    return 0;
}

} signed main() {
#ifdef memset0
	freopen("1.in", "r", stdin);
#endif
	return ringo::main(), 0;
}