#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<queue>
#include<math.h>
#include<deque>

#define ll long long
#define ld long double

using namespace std;

const int maxn = 150005;
vector<int> g[maxn];
int n, m;
int color[maxn];
ll color_size[maxn];

void dfs(int v, int c) {
	color[v] = c;
	for (int u : g[v]) {
		if (color[u] == 0)
			dfs(u, c);
	}
}

void fail() {
	printf("NO");
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int cnt = 1;
	for (int i = 1; i <= n; i++) {
		if (color[i] == 0) 
			dfs(i, cnt++);
	}
	for (int i = 1; i <= n; i++)
		color_size[color[i]]++;

	ll sum = 0;
	for (int i = 1; i < cnt; i++)
		sum += color_size[i] * (color_size[i] - 1) / 2;
	if (sum != m)
		return fail();
	printf("YES");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	solve();
}