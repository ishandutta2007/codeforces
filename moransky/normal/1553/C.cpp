#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;

template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }
template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }

template <typename T> void inline read(T &x) {
	x = 0; int f = 1; char s = getchar();
	while (s > '9' || s < '0') { if (s == '-') f = -1; s = getchar(); }
	while (s <= '9' && s >= '0') x = x * 10 + s - '0', s = getchar();
	x *= f;
}

const int N = 15;

int n = 10, t, d[N], a[N];

char s[N];

int c[2], g[2];

int inline get() {
	int s = 0;
	c[0] = c[1] = 5;
	g[0] = g[1] = 0;
	for (int i = 0; i < n; i++) {
		if (a[i]) g[s]++;
		c[s]--;
		if (c[0] + g[0] < g[1] || c[1] + g[1] < g[0]) return i + 1;
		s ^= 1;
	}
	return 10;
}

int main() {
	int T; read(T);
	while (T--) {
		t = 0;
		scanf("%s", s);
		for (int i = 0; i < n; i++) {
			a[i] = s[i] - '0';
			if (s[i] == '?') d[t++] = i;
		}
		int ans = 2e9;
		for (int i = 0; i < (1 << t); i++) {
			for (int j = 0; j < t; j++) {
				a[d[j]] = i >> j & 1;
			}
			chkMin(ans, get());
		}
		printf("%d\n", ans);
	}
	return 0;
}