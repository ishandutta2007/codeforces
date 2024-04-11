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

template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 3005;

int n, m;

LL ans = 9e18;

vector<int> g[N], t;

int main() {
	read(n), read(m);
	for (int i = 1, p, c; i <= n; i++) {
		read(p), read(c);
		g[p].pb(c);
	}
	for (int i = 1; i <= m; i++) sort(g[i].begin(), g[i].end());
	for (int i = 1; i <= n; i++) {
		LL v = g[1].size(), s = 0; t.clear();
		for (int j = 2; j <= m; j++) {
			int b = max((LL)g[j].size() - (i - 1), 0ll);
			for (int k = 0; k < b; k++)
				s += g[j][k], v++;
			for (int k = b; k < g[j].size(); k++)
				t.pb(g[j][k]);
		}
		if (v < i) {
			sort(t.begin(), t.end());
			int o = i - v;
			for (int j = 0; j < o; j++) {
				s += t[j];
			}
		}
		chkMin(ans, s);
	}
	print(ans);
}