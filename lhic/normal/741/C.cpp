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
int n;
vector<int> eds[220000];
vector<pair<int, int> > ed;
int cl[220000];
int was[220000];

void dfs1(int v, int c) {
	was[v] = 1;
	cl[v] = c;
	for (int u: eds[v])
		if (!was[u])
			dfs1(u, c ^ 1);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
		ed.push_back(make_pair(a, b));
	}
	for (int i = 0; i < 2 * n; i += 2) {
		eds[i].push_back(i + 1);
		eds[i + 1].push_back(i);
	}
	for (int i = 0; i < n * 2; ++i) {
		if (was[i])
			continue;
		dfs1(i, 0);
	}
	for (int i = 0; i < n; ++i) {
		printf("%d %d\n", cl[ed[i].first] + 1, cl[ed[i].second] + 1);
	}
	return 0;
}