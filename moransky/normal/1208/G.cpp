// Skyqwq
#include <iostream>
#include <cstdio>
#include <algorithm>

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

const int N = 1e6 + 5;

int n, k; 

int pr[N], tot, phi[N], d[N], t;

bool st[N];

LL ans = 2;

int main() {
	read(n), read(k);
	if (k == 1) { puts("3"); return 0; }
	phi[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!st[i]) pr[++tot] = i, phi[i] = i - 1;
		for (int j = 1; pr[j] * i <= n; j++) {
			st[pr[j] * i] = 1;
			if (i % pr[j] == 0) {
				phi[i * pr[j]] = phi[i] * pr[j];
				break;
			}
			phi[i * pr[j]] = phi[i] * (pr[j] - 1);
		}
	}
	for (int i = 3; i <= n; i++) d[++t] = phi[i];
	sort(d + 1, d + 1 + t);
	for (int i = 1; i <= k; i++) ans += d[i];
	print(ans);
	return 0;
}