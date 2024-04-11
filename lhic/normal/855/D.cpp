#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/
const int MAXN = 120000;
const int LOG = 20;

int n;
int tin[MAXN];
int tout[MAXN];
vector<int> eds[MAXN];
int p[MAXN];
int t[MAXN];
int up[LOG][MAXN];
int u0[MAXN];
int u1[MAXN];
int h[MAXN];
int tm1;

int is_p(int a, int b) {
	return tin[a] <= tin[b] && tin[b] < tout[a];
}

int lca(int a, int b) {
	if (is_p(a, b))
		return a;
	if (is_p(b, a))
		return b;
	for (int i = LOG - 1; i >= 0; --i) {
		if (!is_p(up[i][a], b))
			a = up[i][a];
	}
	return up[0][a];
}

int cl[MAXN];

void dfs1(int v, int h0, int h1, int c) {
	cl[v] = c;
	tin[v] = tm1++;
	if (t[v] != 0)
		h0 = h[v];
	if (t[v] != 1)
		h1 = h[v];
	u0[v] = h0;
	u1[v] = h1;
	for (int u: eds[v]) {
		h[u] = h[v] + 1;
		dfs1(u, h0, h1, c);
	}
	tout[v] = tm1;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", p + i, t + i);
		if (p[i] == -1) {
			p[i] = i;
		}
		else {
			--p[i];
			eds[p[i]].push_back(i);
		}
		up[0][i] = p[i];
	}
	int cc = 0;
	for (int i = 0; i < n; ++i)
		if (p[i] == i)
			dfs1(i, 0, 0, cc++);
	for (int i = 1; i < LOG; ++i)
		for (int j = 0; j < n; ++j) {
			up[i][j] = up[i - 1][up[i - 1][j]];
		}
	int q;
	scanf("%d", &q);
	while (q--) {
		int tp, a, b;
		scanf("%d%d%d", &tp, &a, &b);
		--a, --b;
		if (a == b) {
			printf("NO\n");
			continue;
		}
		if (cl[a] != cl[b]) {
			printf("NO\n");
			continue;
		}
		if (tp == 1) {
			if (is_p(a, b) && u0[b] <= h[a]) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
		else { 
			swap(a, b);
			int x = lca(a, b);
			if (x != a && u1[a] <= h[x] && u0[b] <= h[x]) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}
	return 0;
}