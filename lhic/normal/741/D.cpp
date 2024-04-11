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
const int MAXN = 510000;
const int LOG = 20;

int p[MAXN];
vector<int> eds[MAXN];
int lc[MAXN];
int tin[MAXN];
int tout[MAXN];
vector<int> gg[1 << 22];
int dp[MAXN];
vector<pair<int, int> > st;
int h[MAXN];
int go[MAXN];
vector<int> vv;
int gol[MAXN];
int n;
vector<int> vk;
int spt[LOG][MAXN * 2];
int pr[MAXN * 2];
int tm1;

void dfs1(int v) {
	tin[v] = vk.size();
	vk.push_back(v);
	for (int u: eds[v]) {
		dfs1(u);
		vk.push_back(v);
	}
}


void buildlca() {
	dfs1(0);
	for (int i = 0; i < 20; ++i) {
		for (int j = (1 << i); j < (1 << (i + 1)) && j <= vk.size(); ++j)
			pr[j] = i;
	}
	for (int i = 0; i < vk.size(); ++i)
		spt[0][i] = vk[i];
	for (int i = 1; i < LOG; ++i) {
		for (int j = 0; j + (1 << i) <= vk.size(); ++j) {
			int x = spt[i - 1][j];
			int y = spt[i - 1][j + (1 << (i - 1))];
			if (h[x] < h[y])
				spt[i][j] = x;
			else
				spt[i][j] = y;
		}
	}
}

int lca(int a, int b) {
	a = tin[a];
	b = tin[b];
	if (a > b)
		swap(a, b);
	int k = pr[b - a + 1];
	int x = spt[k][a];
	int y = spt[k][b - (1 << k) + 1];
	if (h[x] < h[y])
		return x;
	else
		return y;
}

bool cmp(int a, int b) {
	return tin[a] < tin[b];
}


void solve() {
	if (vv.size() == 1)
		return;
	for (int i = 0; i < (int)vv.size() - 1; ++i)
		lc[i] = lca(vv[i], vv[i + 1]);
	int n = vv.size();
	st.clear();
	for (int i = 0; i < n - 1; ++i) {
		int mx = h[vv[i]];
		while (!st.empty() && st.back().first >= h[lc[i]]) {
			mx = max(mx, st.back().second);
			st.pop_back();
		}
		gol[i] = mx;
		st.push_back(make_pair(h[lc[i]], mx));
	}
	st.clear();
	for (int i = n - 1; i > 0; --i) {
		int mx = h[vv[i]];
		while (!st.empty() && st.back().first >= h[lc[i - 1]]) {
			mx = max(mx, st.back().second);
			st.pop_back();
		}
		dp[lc[i - 1]] = max(dp[lc[i - 1]], gol[i - 1] + mx - 2 * h[lc[i - 1]]);
		st.push_back(make_pair(h[lc[i - 1]], mx));
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		char cc;
		scanf("%d %c", p + i, &cc);
		int c = cc - 'a';
		--p[i];
		eds[p[i]].push_back(i);
		go[i] = go[p[i]] ^ (1 << c);
		h[i] = h[p[i]] + 1;
	}
	buildlca();
	for (int i = 0; i < n; ++i) {
		gg[go[i]].push_back(i);
	}
	for (int i = 0; i < (1 << 22); ++i)
		sort(gg[i].begin(), gg[i].end(), cmp);
	for (int i = 0; i < (1 << 22); ++i) {
		if (gg[i].empty())
			continue;
		int fl = 0;
		for (int j = 0; j < 22; ++j) {
			if ((i >> j) & 1) {
				if (!gg[i ^ (1 << j)].empty()) {
					fl = 1;
					vv.clear();
					merge(gg[i].begin(), gg[i].end(), gg[i ^ (1 << j)].begin(), gg[i ^ (1 << j)].end(), back_inserter(vv), cmp);
					solve();
				}
			}
		}
		if (!fl) {
			vv = gg[i];
			solve();
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int u: eds[i])
			dp[i] = max(dp[i], dp[u]);
	}
	for (int i = 0; i < n; ++i)
		printf("%d ", dp[i]);
	printf("\n");
	return 0;
}