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

const int N = 1e3 + 5;

int n, h, a[N], b[N];

bool inline chk(int m) {
	for (int i = 1; i <= m; i++) b[i] = a[i];
	sort(b + 1, b + 1 + m);
	LL res = 0;
	for (int i = m; i >= 1; i -= 2) res += b[i];
	return res <= h;
}

int main() {
	read(n), read(h);
	for (int i = 1; i <= n; i++) read(a[i]);
	int p;
	for (int i = 1; i <= n; i++) {
		if (chk(i)) p = i;
	}
	printf("%d\n", p);
    return 0;
}