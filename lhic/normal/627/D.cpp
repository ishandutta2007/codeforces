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
const int MAXN = 210000;

int was[MAXN];
int sz[MAXN];
int sz1[MAXN];
int n;
int dp[MAXN];
int a[MAXN];
int aa[MAXN];
vector<int> eds[MAXN];
int ans;
int k;

void dfs0(int v) {
	was[v] = 1;
	sz[v] = 1;
	for (int u: eds[v]) {
		if (!was[u])
			dfs0(u), sz[v] += sz[u];
	}
}

void dfs1(int v) {
	was[v] = 1;
	sz1[v] = a[v];
	for (int u: eds[v]) {
		if (!was[u])
			dfs1(u), sz1[v] += sz1[u];
	}
}


void dfs(int v) {
	was[v] = 1;
	int m1 = 0;
	int m2 = 0;
	int sm = 0;
	for (int u: eds[v]) {
		if (was[u])
			continue;
		dfs(u);
		if (sz[u] == sz1[u])
			sm += sz[u];
		else {
			if (m2 < dp[u])
				m2 = dp[u];
			if (m2 > m1)
				swap(m1, m2);
		}
	}
	if (a[v] == 0) {
		dp[v] = 0;
		return;
	}
	dp[v] = sm + 1 + m1;
	if (sz[0] - sz1[0] == sz[v] - sz1[v])
		sm += n - sz[v];
	ans = max(ans, m1 + m2 + 1 + sm);
}



int check(int k) {
	for (int i = 0; i < n; ++i)
		a[i] = (aa[i] >= k ? 1 : 0);
	memset(was, 0, sizeof(was));
	dfs1(0);
	ans = 0;
	memset(was, 0, sizeof(was));
	dfs(0);
	return ans;
}


int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", aa + i);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	dfs0(0);
	int l = 0;
	int r = 1000010;
	while (r - l > 1) {
		int m = (l + r) >> 1;
		if (check(m) >= k)
			l = m;
		else
			r = m;
	}
	cout << l << "\n";
	return 0;
}