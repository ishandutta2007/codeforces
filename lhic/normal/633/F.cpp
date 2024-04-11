#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 120000;
ll ans = 0;
int n;
vector<int> eds[MAXN];
int h[MAXN];
ll a[MAXN];
int was[MAXN];
ll dp1[MAXN];
ll dp2[MAXN];
ll dp3[MAXN];


void dfs(int v) {
	was[v] = 1;
	ll m11 = 0, m12 = 0;
	pair<ll, ll> m21 = make_pair(0, 0), m22 = make_pair(0, 0), m23 = make_pair(0, 0);
	int fl = 0;
	for (int u: eds[v]) {
		if (!was[u]) {
			fl = 1;
			h[u] = h[v] + 1, dfs(u);
			dp2[v] = max(dp2[v], a[v] + dp2[u]);
			dp1[v] = max(dp1[v], dp1[u]);
			m12 = max(m12, dp1[u]);
			if (m12 > m11)
				swap(m12, m11);
			m23 = max(m23, make_pair(dp2[u], (ll)u));
			if (m23 > m22)
				swap(m23, m22);
			if (m22 > m21)
				swap(m22, m21);
			dp3[v] = max(dp3[v], dp3[u] + a[v]);
		}
	}
	if (!fl) {
		dp1[v] = a[v];
		dp2[v] = a[v];
		dp3[v] = a[v];
		return;
	}
	dp1[v] = max(dp1[v], a[v] + m21.first + m22.first);
	for (int u: eds[v]) {
		if (h[u] != h[v] + 1)
			continue;
		if (m21.second != u)
			dp3[v] = max(dp3[v], a[v] + m21.first + dp1[u]);
		else 
			dp3[v] = max(dp3[v], a[v] + m22.first + dp1[u]);
	}
	ans = max(ans, m11 + m12);
	for (int u: eds[v]) {
		if (h[u] != h[v] + 1)
			continue;
		if (m21.second != u && m22.second != u) {
			ans = max(ans, dp1[u] + m21.first + m22.first + a[v]);
		}
		else if (m21.second != u && m23.second != u) {
			ans = max(ans, dp1[u] + m21.first + m23.first + a[v]);
		}
		else {
			ans = max(ans, dp1[u] + m22.first + m23.first + a[v]);
		}
		if (u != m21.second)
			ans = max(ans, dp3[u] + a[v] + m21.first);
		else
			ans = max(ans, dp3[u] + a[v] + m22.first);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", a + i);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	memset(was, 0, sizeof(was));
	dfs(0);
	cout << ans << "\n";
	return 0;
}