// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 55;

int n, m, f[N << 1];

char g[N][N], s[N][N];

int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}

void merge(int x, int y) {
	f[find(x)] = find(y);
}

vector<int> b[N << 1];

int main() {
	read(n), read(m);
	for (int i = 1; i <= n + m; i++) f[i] = i; 
	for (int i = 1; i <= n; i++) {
		scanf("%s", g[i] + 1);
		int la = -1;
		for (int j = 1; j <= m; j++) {
			s[i][j] = '.';
			if (g[i][j] == '#') {
				merge(i, j + n);
				if (la == -1) la = j;
				else {
					merge(la + n, j + n);
				}
			}
		}
	}
	for (int j = 1; j <= m; j++) {
		int la = -1;
		for (int i = 1; i <= n; i++) {
			if (g[i][j] == '#') {
				if (la == -1) la = i;
				else merge(i, la);
			}
		}
	}
	for (int i = 1; i <= n + m; i++) {
		b[find(i)].pb(i);
	}
	for (int i = 1; i <= n + m; i++) {
		for (int x: b[i]) {
			for (int y: b[i]) {
				if (x <= n && y > n) {
					s[x][y - n] = '#';
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i][j] != g[i][j]) {
				puts("No"); return 0;
			}
		}
	}
	puts("Yes");
    return 0;
}