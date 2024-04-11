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
 
template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 5e5 + 5;

int n, m, a[N];
 
priority_queue<int> q;

int main() {
	read(n);
	LL s = 0;
	for (int i = 1; i <= n; i++) read(a[i]), a[i] -= i, s += a[i];
	for (int i = 1; i <= n; i++) {
		q.push(a[i]), q.push(a[i]);
		while (q.size() > i) q.pop();
	}
	LL x = q.top();
	LL ans = -n * x + s;
	while (q.size()) {
		LL t = q.top(); q.pop();
		ans += (x - t);
	}
	printf("%lld\n", ans);
	return 0;
}