// xtqqwq
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

const int N = 505;

int n, m, a[N][N], b[N][N];

void inline work(int w[N][N]) {
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (w[i][j]) {
				w[i][j] ^= 1, w[i + 1][j] ^= 1;
				w[i][j + 1] ^= 1, w[i + 1][j + 1] ^= 1;
			}
		}
	}
}

bool inline chk() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) if (a[i][j] != b[i][j]) return 0;
	return 1;
}

int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) read(a[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) read(b[i][j]);
	work(a), work(b);
	puts(chk() ? "Yes" : "No");
    return 0;
}