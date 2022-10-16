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

int n, c[N];

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(c[i]);
	int a = 1;
	int b = 1;
	while (c[a] == c[b]) b++;
	int ans = 0;
	for (int i = b; i <= n; i++) {
		if (c[i] != c[1]) chkMax(ans, i - 1);
		if (c[i] != c[b]) chkMax(ans, i - b);
	}
	printf("%d\n", ans);
    return 0;
}