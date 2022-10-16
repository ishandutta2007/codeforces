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

const int N = 1e3 + 5;

int n, k1, k2, a[N], b[N], k;

priority_queue<int> q;

LL ans;

int main() {
	read(n), read(k1), read(k2);
	k = k1 + k2;
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) {
		read(b[i]);
		ans += (LL)(a[i] - b[i]) * (a[i] - b[i]);	
		if (a[i] != b[i]) q.push(abs(a[i] - b[i]));
	}
	int g = 0;
	for (int i = 0; i < k; i++) {
		if (q.empty()) {
			++g;
			continue;
		}
		int u = q.top(); q.pop();
		ans -= 1ll * u * u;
		--u;
		ans += 1ll * u * u;
		if (u) q.push(u);
	}
	if (g & 1) ans++;
	printf("%lld\n", ans);
    return 0;
}