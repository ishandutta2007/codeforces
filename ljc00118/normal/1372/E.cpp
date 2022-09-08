#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 105;

pii g[N][N];
int f[N][N];
int n, m;

int main() {
	read(n); read(m);
	for (int i = 1; i <= n; i++) {
		int k; read(k);
		for (int j = 1; j <= k; j++) {
			int l, r; read(l); read(r);
			for (int t = l; t <= r; t++) g[t][i] = make_pair(l, r);
		}
	}
	for (int len = 1; len <= m; len++) {
		for (int l = 1; l <= m - len + 1; l++) {
			int r = l + len - 1;
			for (int i = l; i <= r; i++) {
				int cnt = 0;
				for (int j = 1; j <= n; j++) {
					if (l <= g[i][j].first && g[i][j].second <= r && g[i][j].first <= i && i <= g[i][j].second) ++cnt;
				}
				f[l][r] = max(f[l][r], f[l][i - 1] + f[i + 1][r] + cnt * cnt);
			}
		}
	}
	print(f[1][m], '\n');
	return 0;
}