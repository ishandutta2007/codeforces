#ifndef LOCAL
#pragma GCC optimize "-O3"
#endif
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

const int MAXN = 600;

vector<pair<int, int> > st;

vector<pair<int, int> > eds[MAXN];

int was[MAXN];

int n, m;
vector<pair<int, int>> vv;

int dfs1(int v) {
	was[v] = 1;
	for (auto e: eds[v]) {
		int u = e.first;
		if (was[u] == 1) {
			reverse(st.begin(), st.end());
			while (st.back().first != u)
				st.pop_back();
			st.back().second = e.second;
			reverse(st.begin(), st.end());
			vv = st;
			return 1;
		}
		else if (!was[u]){
			st.push_back(make_pair(u, e.second));
			if (dfs1(u)) {
				return 1;
			}
		}
	}
	was[v] = 2;
	return 0;
}

int gx;

int dfs2(int v) {
	was[v] = 1;
	for (auto e: eds[v]) {
		int u = e.first;
		if (e.second == gx || was[u] == 2)
			continue;
		if (was[u] == 1)
			return 1;
		if (dfs2(u))
			return 1;
	}
	was[v] = 2;
	return 0;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		eds[a].push_back(make_pair(b, i));
	}
	for (int i = 0; i < n; ++i) {
		if (was[i])
			continue;
		st.clear();
		st.push_back(make_pair(i, 0));
		if (dfs1(i)) {
			break;
		}
	}
	if (!vv.size()) {
		cout << "YES\n";
		return 0;
	}

	for (int i = 0; i < vv.size(); ++i) {
		gx = vv[i].second;
		int fl = 0;
		memset(was, 0, sizeof(was[0]) * n);
		for (int j = 0; j < n; ++j) {
			if (!was[j]) {
				if (dfs2(j)) {
					fl = 1;
					break;
				}
			}
		}
		if (!fl) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}