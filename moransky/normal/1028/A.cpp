// Skyqwq
#include <iostream>
#include <cstdio>

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
	if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}
 
const int N = 205;

int n, m, L1, R1, L2, R2;

char s[N][N];

int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s[i] + 1);
		for (int j = 1; j <= m; j++) {
			if (s[i][j] == 'B') {
				if (!L1) L1 = i, R1 = j;
				L2 = i, R2 = j;
			}
		}
	}
	printf("%d %d\n", (L1 + L2) / 2, (R1 + R2) / 2);
	return 0;
}