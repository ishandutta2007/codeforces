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

const int N = 1e5 + 5;

int r, n, f[N], t[N], x[N], y[N], ans, mx[N];

int main() {
	memset(f, 0xcf, sizeof f);
	read(r), read(n);
	f[0] = 0;
	x[0] = y[0] = 1;
	for (int i = 1; i <= n; i++) {
		read(t[i]), read(x[i]), read(y[i]);
		for (int j = i - 1; j >= 0; j--) {
			if (t[i] - t[j] > 2 * r) {
				chkMax(f[i], mx[j] + 1);
				break;
			}
			if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j])
				chkMax(f[i], f[j] + 1);
		}
		chkMax(ans, f[i]);
		mx[i] = max(mx[i - 1], f[i]);
	}
	printf("%d\n", ans);
    return 0;
}