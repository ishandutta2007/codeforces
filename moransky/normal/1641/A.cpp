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

int n;
LL a[N], x;

map<LL, int> M;

int main() {
	int T; read(T);
	while (T--) {
		M.clear();
		read(n);
		read(x);
		for (int i = 1; i <= n; i++) read(a[i]);
		sort(a + 1, a + 1 + n);
		for (int i = 1; i <= n; i++) {
			if (a[i] % x == 0 && M[a[i] / x]) {
				M[a[i] / x]--;
			} else {
				M[a[i]]++;
			}
		}
		LL ans = 0;
		for (auto o: M) ans += o.se;
		printf("%lld\n", ans);
	}
    return 0;
}