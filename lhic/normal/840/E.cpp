#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

const int MAXN = 50100;
const int C = 256;
int go[MAXN][C];
int dp[2][MAXN][C];
vector<int> eds[MAXN];
int p[MAXN];
int h[MAXN];
int a[MAXN];
int p2[MAXN];
int pp[9][MAXN];
int n, q;
int was[MAXN];

int gt(int x) {
	return x >> 8;
}
int gt2(int x) {
	return x & 255;
}

void dfs1(int v) {
	was[v] = 1;
	for (int u: eds[v]) {
		if (was[u])
			continue;
		p[u] = v;
		h[u] = h[v] + 1;
		dfs1(u);
	}
	if (h[v] >= C) {
		int x = v;
		for (int j = 0; j < C; ++j) {
			go[v][gt(a[x])] = max(go[v][gt(a[x])], gt2(a[x]) ^ j);
			x = p[x];
		}
	}
	for (int i = 0; i < C; ++i)
		dp[0][v][i] = (gt(a[v]) ^ i);
}


void init() {
	dfs1(0);
	for (int i = 0; i < n; ++i)
		pp[0][i] = p[i];
	for (int i = 1; i <= 8; ++i) {
		for (int j = 0; j < n; ++j)
			pp[i][j] = pp[i - 1][pp[i - 1][j]];
	}
	for (int i = 0; i < n; ++i) {
		if (h[i] >= C) {
			p2[i] = pp[8][i];
		}
		else {
			p2[i] = -1;
		}
	}
	for (int i = 1; i <= 8; ++i) {
		for (int j = 0; j < n; ++j) {
			if (h[j] >= (1 << i))
				for (int k = 0; k < C; ++k)
					dp[i & 1][j][k] = max(dp[1 - (i & 1)][j][k], dp[1 - (i & 1)][pp[i - 1][j]][k]);
		}
	}
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	init();
	for (int i = 0; i < q; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		int ans = 0;
		int cur = 0;
		int mx = 0;
		int x = v;
		while (h[u] + C <= h[x]) {
			mx = max(mx, dp[0][x][cur]);
			++cur;
			x = p2[x];
		}
		x = v;
		cur = 0;
		while (h[u] + C <= h[x]) {
			ans = max(ans, go[x][mx ^ cur]);
			++cur;
			x = p2[x];
		}
		ans += (mx << 8);
		cur <<= 8;
		while (h[x] >= h[u]) {
			ans = max(ans, a[x] ^ cur);
			if (x == 0)
				break;
			++cur;
			x = p[x];
		}
		printf("%d\n", ans);
	}
    return 0;
}