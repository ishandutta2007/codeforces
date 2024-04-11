// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5;

int n, a[N];

LL s[N];

LL K, B, ans;

void inline calc(LL L, LL R) {
	chkMax(ans, L * K + B);
	chkMax(ans, R * K + B);
}

int main() {
	int T; read(T);
	while (T--) {
		read(n);
		for (int i = 1; i <= n; i++) read(a[i]);
		sort(a + 1, a + 1 + n);
		for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
		LL A = (a[1] * (n - 1ll) + s[n] - a[1]);
		LL b = (a[n] * (n - 1ll) + s[n - 1]);
		if ((A > 0 && b > 0) || (A < 0 && b < 0)) puts("INF");
		else {
			ans = -1e18;
			K = A, B = 0;
			for (int i = 2; i <= n; i++) B += 1ll * a[1] * a[i];
			calc(-a[2], -a[1]);
			for (int i = 2; i < n; i++) {
				K -= a[1] + a[i];
				K += a[n] + a[i];
				B -= 1ll * a[1] * a[i];
				B += 1ll * a[n] * a[i];
				
				calc(-a[i + 1], -a[i]);
			}
			printf("%lld\n", ans);
		}
	}
    return 0;
}