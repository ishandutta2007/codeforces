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

int n, a[N][N], t;

PII e[N * N];

int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		a[i][i] = 1;
		a[i][i + 1] = 1;
		a[i][i - 1] = 1;
		a[i + 1][i] = 1;
		a[i - 1][i] = 1;
		a[i + 1][i + 1] = 1;
		a[i - 1][i - 1] = 1;
	}
	for (int i = 0; i < N; i++)  {
		for (int j = 0; j < N; j++) {
			if (a[i][j]) e[++t] = mp(i, j);
		}
	}
	printf("%d\n", t);
	for (int i = 1; i <= t; i++) printf("%d %d\n", e[i].fi, e[i].se);
    return 0;
}