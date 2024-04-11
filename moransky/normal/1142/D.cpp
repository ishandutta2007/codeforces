// Skyqwq
#include <iostream>
#include <cstdio>
#include <cstring>
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(-x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

int inline get(int i, int j) {
	if (j < i) {
		return (9 + i * (i - 1) / 2 + j + 1) % 11;
	} else return 0;
}

const int N = 1e5 + 5;

int n, f[N][11];

char s[N];

LL ans;

int main() {
	scanf("%s", s + 1); n = strlen(s + 1);
	for (int i = 1; i <= n; i++) {
		int c = s[i] - '0';
		if (c) f[i][c] = 1;
		for (int j = c + 1; j < 11; j++)
			f[i][get(j, c)] += f[i - 1][j];
		for (int j = 0; j < 11; j++) ans += f[i][j]; 	
	}
	print(ans);
	return 0;
}