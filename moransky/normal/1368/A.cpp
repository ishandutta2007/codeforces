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

int main() {
	int T; read(T);
	while (T--) {
		LL a, b, n; read(a), read(b), read(n);
		int c = 0;
		while (a <= n && b <= n) {
			if (a > b) swap(a, b);
			a += b;
			c++;
		}
		printf("%d\n", c);
	}
    return 0;
}