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

const int N = 500005;

int p[N], n, c[N], z[N];

void inline add(int x, int k) {
	for (; x <= n; x += x & -x) c[x] += k;
}

int inline ask(int x) {
	int ret = 0;
	for (; x; x -= x & -x) ret += c[x];
	return ret;
}

void inline clr() {
	for (int i = 1; i <= n; i++) c[i] = 0;
}

int main() {
	int T; read(T);
	while (T--) {
		read(n);
		for (int i = 1; i <= n; i++) read(p[i]);
		LL ans = 0;
		for (int i = 1; i <= n; i++) {
			int o = ask(p[i]);
			ans += (i - 1 - o);
			z[i] = o - (i - 1 - o);
			add(p[i], 1);
		}
		clr();
		for (int i = n; i; i--) {
			z[i] += 2 * ask(p[i]);
			add(p[i], 1);
		}
		sort(z + 1, z + 1 + n);
		printf("%lld ", ans);
		for (int i = 1; i <= n; i++)
			ans += z[i] - (i - 1), printf("%lld ", ans);
		puts("");
		clr();
	}
    return 0;
}