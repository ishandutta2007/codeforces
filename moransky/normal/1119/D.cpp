
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

const int N = 1e5 + 5;

int n, q, t;

LL s[N], d[N], sum[N];

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(s[i]);
	read(q);
	sort(s + 1, s + 1 + n);
	n = unique(s + 1, s + 1 + n) - s - 1;
	for (int i = 1; i < n; i++)
		d[++t] = s[i + 1] - s[i];
	sort(d + 1, d + 1 + t);
	for (int i = 1; i <= t; i++) sum[i] = sum[i - 1] + d[i];
	while (q--) {
		LL l, r; read(l), read(r);
		LL x = r - l + 1;
		int p = lower_bound(d + 1, d + 1 + t, x) - d;
		LL ans = sum[p - 1] + (n - p + 1ll) * x;
		printf("%lld ", ans);
	}
    return 0; 
}