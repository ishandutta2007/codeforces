#include <iostream>
#include <cstdio>
#include <cstring>
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long LL;

using namespace std;

template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }


template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

template <typename T> void print(T x) {
    if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 105, P = 1e9 + 7;

int n, a[N], f[N][N * N], cnt[N], m, ans, C[N][N], num;

int main() {
    read(n);
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
	}
    for (int i = 1; i <= n; i++) {
		read(a[i]);
		if (!cnt[a[i]]) num++;
		cnt[a[i]]++;
	}
    f[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		m += a[i];
		for (int j = m; j >= a[i]; j--) {
			for (int k = i; k; k--)
				(f[k][j] += f[k - 1][j - a[i]]) %= P;
		}
	}
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= cnt[i]; j++) {
			if (f[j][i * j] == C[cnt[i]][j]) {
				chkMax(ans, j);
				if (num == 2 && j == cnt[i]) chkMax(ans, n);
			}
		}
	}
	print(ans);
}