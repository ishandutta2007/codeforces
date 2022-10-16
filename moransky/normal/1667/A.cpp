// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 5005;

int n, a[N];

LL ans;

void inline wk(int p) {
	LL now = 1;
	LL c = 0;
	for (int i = p + 1; i <= n; i++) {
		LL t = (now + a[i] - 1) / a[i];
		c += t;
		now = a[i] * t + 1;
	}
	now = 1;
	for (int i = p - 1; i; i--) {
		LL t = (now + a[i] - 1) / a[i];
		c += t;
		now = a[i] * t + 1;
	}
	chkMin(ans, c);
}

int main() {
	read(n); ans = 9e18;
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) wk(i);
	printf("%lld\n", ans);
    return 0;
}