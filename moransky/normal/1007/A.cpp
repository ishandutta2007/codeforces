#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long LL;

using namespace std;

template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }


template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e5 + 5;

int n, a[N], t = 1;

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	sort(a + 1, a + 1 + n);
	int ans = 0;
	for (int i = 1, j = 1; i <= n; i++) {
		while (j <= n && (j < i || a[j] == a[i])) j++;
		if (j > n) break;
		chkMax(t, j - i);
		if (i + t > n) break;
		chkMax(ans, i);
	}
	printf("%d\n", ans);
}