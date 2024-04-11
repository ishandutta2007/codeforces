// Skyqwq
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define pb push_back
using namespace std;

typedef long long LL;

// char buf[1<<23], *p1=buf, *p2=buf, obuf[1<<23], *O=obuf;
// #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<21, stdin), p1 == p2) ? EOF : *p1++)

void inline read(int &x) {
    x = 0; char s = getchar();
    while (s < '0' || s > '9') s = getchar();
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
}

void print(int x) {
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 305, P = 998244353;

int n, ans, t;

int inline power(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % P;
		a = (LL)a * a % P;
		b >>= 1;
	}
	return res;
}

vector<int> e[N];

void inline add(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}

int f[N][N], g[N][N], tf[N], tg[N], dep[N], cnt[N];

void dfs(int u, int fa) {
	f[u][0] = 1, g[u][t] = 1;
	dep[u] = 0;
	for (int k = 0; k < e[u].size(); k++) {
		int v = e[u][k];
		if (v == fa) continue;
		dfs(v, u);
		memset(tf, 0, sizeof tf);
		memset(tg, 0, sizeof tg);
		int s = 0;
		for (int i = 0, j = 0; i <= dep[u]; i++) {
			while (j + 1 <= i && j <= dep[v]) add(s, f[v][j]), j++;
			add(tf[i], (LL)s * f[u][i] % P);
		}
		s = 0;
		for (int j = 0, i = 0; j <= dep[v]; j++) {
			while (j + 1 > i && i <= dep[u]) add(s, f[u][i]), i++;
			add(tf[j + 1], (LL)s * f[v][j] % P);
		}
		// for (int i = 0; i <= dep[u]; i++) {
		// 	for (int j = 0; j <= dep[v]; j++) {
		// 		add(tf[max(i, j + 1)], (LL)f[u][i] * f[v][j] % P);
		// 	}
		// }

		s = 0;
		for (int i = 0, j = 0; i <= dep[u]; i++) {
			while (j - 1 < i && j <= t) add(s, g[v][j]), j++;
			add(tf[i], (LL)s * f[u][i] % P);
		}
		s = 0;
		for (int j = 0, i = 0; j <= t; j++) {
			while (j - 1 >= i && i <= dep[u]) add(s, f[u][i]), i++;
			if (j) add(tg[j - 1], (LL)s * g[v][j] % P);
		}

		// for (int i = 0; i <= dep[u]; i++) {
		// 	for (int j = 0; j <= t; j++) {
		// 		int w = (LL)f[u][i] * g[v][j] % P;
		// 		if (i <= j - 1) add(tg[j - 1], w);//, cout << " gx g*f -> g2 " << i << " " << j << " " << w << endl;
		// 		else add(tf[i], w);
		// 	}
		// }

		s = 0;
		for (int i = 0, j = 0; i <= t; i++) {
			while (j + 1 <= i && j <= dep[v]) add(s, f[v][j]), j++;
			add(tg[i], (LL)s * g[u][i] % P);
		}
		s = 0;
		for (int j = 0, i = 0; j <= dep[v]; j++) {
			while (j + 1 > i && i <= t) add(s, g[u][i]), i++;
			add(tf[j + 1], (LL)s * f[v][j] % P);
		}

		// for (int i = 0; i <= t; i++) {
		// 	for (int j = 0; j <= dep[v]; j++) {
		// 		int w = (LL)g[u][i] * f[v][j] % P;
		// 		if (j + 1 <= i) add(tg[i], w);//, cout << " gx g*f -> g " << i << " " << j << " " << w << endl; 
		// 		else add(tf[j + 1], w);
		// 	}
		// }
		s = 0;
		for (int i = 0, j = 0; i <= t; i++) {
			while (j - 1 <= i && j <= t) add(s, g[v][j]), j++;
			add(tg[i], (LL)s * g[u][i] % P);
		}
		s = 0;
		for (int j = 0, i = 0; j <= t; j++) {
			while (j - 1 > i && i <= t) add(s, g[u][i]), i++;
			add(tg[j - 1], (LL)s * g[v][j] % P);
		}
		
		dep[u] = max(dep[u], dep[v] + 1);
		for (int i = 0; i <= t; i++) g[u][i] = tg[i];
		for (int i = 0; i <= dep[u]; i++) f[u][i] = tf[i];
	}
	// cout << " is FOr " << u << endl;
	// for (int i = 0; i <= t; i++) cout << g[u][i] << " ";
	// puts("F_>>>");
	// for (int i = 0; i <= dep[u]; i++) cout << f[u][i] << " ";
	// puts("");
}

int main() {
	read(n);
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), e[u].pb(v), e[v].pb(u);
	ans = P - 1;
	for (t = 1; t <= n; t++) {
		memset(f, 0, sizeof f);
		memset(g, 0, sizeof g);
		dfs(1, 0);
		int s = 0;
		for (int i = 0; i <= t; i++) add(s, g[1][i]);
		//cout << t - 1 << " sum ->>> " << s << endl;
		cnt[t - 1] = s;
		//add(ans, s);
	}
	cnt[n] = power(2, n);
	for (int i = n; i; i--) {
		add(cnt[i], P - cnt[i - 1]);
	}
	add(cnt[0], P - 1);
	for (int i = 0; i <= n; i++) add(ans, (LL)i * cnt[i] % P);//, cout << cnt[i] * i << " qwq\n";
	//cout << ans << endl;
	ans = (LL)ans * power(power(2, n), P - 2) % P;
	printf("%d\n", ans);
	return 0;
}