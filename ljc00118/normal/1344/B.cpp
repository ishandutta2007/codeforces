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

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const int N = 1005;

char c[N][N];
int f[N * N];
int n, m, w1, w2, ans;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main() {
	read(n); read(m);
	for (int i = 1; i <= n * m; i++) f[i] = i;
	for (int i = 1; i <= n; i++) scanf("%s", c[i] + 1);
	for (int i = 1; i <= n; i++) {
		bool ok = 1, bw = 0;
		for (int j = 2; j <= m; j++) {
			if (bw && c[i][j] == '#') {
				ok = 0;
				break;
			}
			if (c[i][j - 1] == '#' && c[i][j] == '.') bw = 1;
		}
		if (!ok) {
			print(-1, '\n');
			return 0;
		}
	}
	for (int j = 1; j <= m; j++) {
		bool ok = 1, bw = 0;
		for (int i = 2; i <= n; i++) {
			if (bw && c[i][j] == '#') {
				ok = 0;
				break;
			}
			if (c[i - 1][j] == '#' && c[i][j] == '.') bw = 1;
		}
		if (!ok) {
			print(-1, '\n');
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		bool ok = 1;
		for (int j = 1; j <= m; j++) if (c[i][j] == '#') ok = 0;
		w1 |= ok;
	}
	for (int j = 1; j <= m; j++) {
		bool ok = 1;
		for (int i = 1; i <= n; i++) if (c[i][j] == '#') ok = 0;
		w2 |= ok;
	}
	if (w1 ^ w2) {
		print(-1, '\n');
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int d = 0; d < 4; d++) {
				int x = i + dx[d], y = j + dy[d];
				if (x == 0 || y == 0 || x > n || y > m) continue;
				if (c[i][j] == '#' && c[x][y] == '#') f[find((i - 1) * m + j)] = find((x - 1) * m + y);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (c[i][j] == '#' && find((i - 1) * m + j) == (i - 1) * m + j) {
				++ans;
			}
		}
	}
	print(ans, '\n');
    return 0;
}