// Skyqwq
#include <bits/stdc++.h>

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

const int N = 2e5 + 5, P = 998244353;

int n, k, a[N], p[N];
 
bool st[N];

LL s;

int ans = 1;

int main() {
	read(n), read(k);
	for (int i = 1; i <= n; i++) read(a[i]), p[a[i]] = i;
	for (int i = n; i > n - k; i--) s += i, st[p[i]] = 1;
	for (int i = 1; i <= n; i++) {
		if (st[i]) continue;
		int j = i;
		while (j < n && !st[j + 1]) ++j;
		if (i > 1 && j < n) ans = 1ll * ans * (j - i + 2) % P;
		i = j;
	}
	printf("%lld %d\n", s, ans);
	return 0;
}