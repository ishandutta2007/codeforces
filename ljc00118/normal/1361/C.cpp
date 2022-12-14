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

const int N = 1 << 20 | 100;

vector <int> g[N];
int a[N], f[N], go[N];
int n;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void merge(int x, int y) {
	int _x = go[x], _y = go[y];
	go[x] = _y; go[y] = _x; go[_x] = y; go[_y] = x;
}

void check(int bit) {
	int mx = (1 << (bit + 1)) - 1;
	for (int i = 0; i <= mx; i++) g[i].clear();
	for (int i = 1; i <= n * 2; i++) g[a[i] & mx].push_back(i);
	for (int i = 0; i <= mx; i++) if (g[i].size() & 1) return;
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 0; i <= mx; i++) {
		for (int j = 0; j < (int)g[i].size(); j += 2) {
			go[g[i][j]] = g[i][j + 1];
			go[g[i][j + 1]] = g[i][j];
			f[find((g[i][j] + 1) / 2)] = find((g[i][j + 1] + 1) / 2);
		}
	}
	for (int i = 0; i <= mx; i++) {
		if (g[i].size() == 0) continue;
		int fir = g[i][0];
		for (int j = 1; j < (int)g[i].size(); j++) {
			if (find((fir + 1) / 2) != find((g[i][j] + 1) / 2)) {
				merge(fir, g[i][j]);
				f[find((fir + 1) / 2)] = find((g[i][j] + 1) / 2);
			}
		}
	}
	int fir = find(1);
	for (int i = 2; i <= n; i++) if (find(i) != fir) return;
	int now = 1;
	print(bit + 1, '\n');
	for (int i = 1; i <= n; i++) {
		print(now, ' ');
		now = ((now - 1) ^ 1) + 1;
		print(now, ' ');
		now = go[now];
	}
	putchar('\n');
	exit(0);
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i * 2 - 1]), read(a[i * 2]);
	for (int bit = 19; bit >= 0; bit--) check(bit);
	print(0, '\n');
	for (int i = 1; i <= n * 2; i++) print(i, ' ');
	putchar('\n');
    return 0;
}