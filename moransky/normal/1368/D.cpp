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

const int N = 2e5 + 5;

int n, a[N], cnt[20], b[N];

int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		for (int j = 0; j < 20; j++) {
			if (a[i] >> j & 1) cnt[j]++;
		}
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 1; j <= cnt[i]; j++)
			b[j] |= 1 << i;
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
		ans += 1ll * b[i] * b[i];
	printf("%lld\n", ans);
	
    return 0;
}