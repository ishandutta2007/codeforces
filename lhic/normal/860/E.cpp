#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
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

int n;
vector<int> eds[MAXN];
int sz[MAXN];
int h[MAXN];
ll ans[MAXN];
int mh[MAXN];

void dfs1(int v, int p) {
	sz[v] = 1;
	mh[v] = 0;
	for (int u: eds[v]) {
		if (u == p)
			continue;
		h[u] = h[v] + 1;
		dfs1(u, v);
		mh[v] = max(mh[v], mh[u] + 1);
		sz[v] += sz[u];
	}
}

int cur[MAXN];

void dfs3(int v, int p, int add) {
	cur[h[v]] += add;
	for (int u: eds[v]) {
		if (u == p)
			continue;
		dfs3(u, v, add);
	}
}

void dfs4(int v, int p, int now, const vector<int> &vv, int add, ll cursum) {
	if (now >= 0)
		cursum += vv[now];
	ans[v] += cursum * add;
	for (int u: eds[v]) {
		if (u == p)
			continue;
		dfs4(u, v, now - 1, vv, add, cursum);
	}
}

void dfs5(int v, int p, vector<int> &vv, int now) {
	vv[now] += 1;
	for (int u: eds[v]) {
		if (u == p)
			continue;
		dfs5(u, v, vv, now - 1);
	}
}

vector<int> dfs2(int v, int p, ll cursum, int add) {
	int bst = -1;
	for (int u: eds[v]) {
		if (u == p)
			continue;
		if (bst == -1 || sz[u] > sz[bst])
			bst = u;
	}
	cur[h[v]] += add + 1;
	cursum += cur[h[v]];
	ans[v] += cursum;
	if (bst == -1) {
		cur[h[v]] -= add + 1;
		return {1};
	}
	for (int u: eds[v]) {
		if (u == p || u == bst)
			continue;
		dfs3(u, v, add + 1);
	}
	for (int u: eds[v]) {
		if (u == p || u == bst)
			continue;
		dfs2(u, v, cursum, 0);
	}
	vector<int> tmp = dfs2(bst, v, cursum, add + 1);
	for (int u: eds[v]) {
		if (u == p || u == bst)
			continue;
		dfs4(u, v, tmp.size() - 1, tmp, add + 1, 0);
	}
	for (int u: eds[v]) {
		if (u == p || u == bst)
			continue;
		dfs3(u, v, -add - 1);
	}
	tmp.push_back(1);
	if (mh[v] + 1 > tmp.size()) {
		vector<int> tmp2(mh[v] + 1 - tmp.size());
		for (int i: tmp)
			tmp2.push_back(i);
		tmp = tmp2;
	}
	for (int u: eds[v]) {
		if (u == p || u == bst)
			continue;
		dfs5(u, v, tmp, tmp.size() - 2);
	}
	cur[h[v]] -= add + 1;
	return tmp;
}

int main() {
#ifdef BZ
	freopen("in", "r", stdin);
#endif
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	int root = -1;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		--x;
		if (x == -1)
			root = i;
		else
			eds[x].push_back(i);
	}
	dfs1(root, -1);
	dfs2(root, -1, 0, 0);
	for (int i = 0; i < n; ++i)
		cout << ans[i] - (h[i] + 1) << " ";
	cout << "\n";
	return 0;
}