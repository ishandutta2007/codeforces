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

const int N = 1e4 + 5;

LL X, d;

int n;

LL a[N];

int main() {
	read(X), read(d);
	LL now = 1;
	while (X) {
		int p; LL k;
		for (int i = 60; ~i; i--) {
			LL t = (1ll << i) - 1;
			if (t <= X) {
				k = t, p = i;
				break;
			}
		}
		while (p--) a[++n] = now;
		X -= k;
		now += d;
	}
	printf("%d\n", n);
	for (int i = 1; i <= n; i++) printf("%lld ", a[i]);
    return 0;
}