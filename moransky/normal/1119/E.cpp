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

const int N = 3e5 + 5;

int n;

LL a[N];

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	LL ans = 0, t = 0;
	for (int i = 1; i <= n; i++) {
		LL w = min(t, a[i] / 2);
		a[i] -= 2 * w;
		t -= w;
		ans += w;
		w = a[i] / 3;
		a[i] -= 3 * w;
		ans += w;
		t += a[i];
	}
	printf("%lld\n", ans);
    return 0;
}