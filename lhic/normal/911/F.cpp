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
const int MAXN = 210000;

ll ans;
int dp1[MAXN];
int dp2[MAXN];
vector<pair<int, int> > go;
vector<pair<int, int> > vv;
vector<int> eds[MAXN];
int n;

pair<int, int> dfs1(int v, int p) {
	pair<int, int> ans = make_pair(0, v);
	for (int u: eds[v]) {
		if (u == p)
			continue;
		pair<int, int> tmp = dfs1(u, v);
		++tmp.first;
		ans = max(ans, tmp);
	}
	return ans;
}

void dfs2(int v, int p, int d, int *dp) {
	dp[v] = d;
	for (int u: eds[v]) {
		if (u == p)
			continue;
		dfs2(u, v, d + 1, dp);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	int a = dfs1(0, -1).second;
	int b = dfs1(a, -1).second;
	dfs2(a, -1, 0, dp1);
	dfs2(b, -1, 0, dp2);
	int d = dp1[b];
	for (int i = 0; i < n; ++i) {
		if (dp1[i] + dp2[i] == d) {
			go.push_back(make_pair(dp1[i], i));
		}
		else {
			ans += max(dp1[i], dp2[i]);
			vv.push_back(make_pair(max(dp1[i], dp2[i]), i));
		}
	}
	sort(vv.begin(), vv.end());
	reverse(vv.begin(), vv.end());
	sort(go.begin(), go.end());
	vector<pair<int, int> > vans;
	for (auto i: vv) {
		int x = i.second;
		if (dp1[x] > dp2[x]) {
			vans.push_back(make_pair(a, x));
		}
		else {
			vans.push_back(make_pair(b, x));
		}
	}
	for (int i = 0; i < go.size() - 1; ++i) {
		int x = go[i].second;
		ans += dp2[x];
		vans.push_back(make_pair(b, x));
	}
	printf("%lld\n", ans);
	for (int i = 0; i < vans.size(); ++i) {
		printf("%d %d %d\n", vans[i].first + 1, vans[i].second + 1, vans[i].second + 1);
	}
	return 0;
}