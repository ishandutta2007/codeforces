#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define pb push_back
using namespace std;

typedef long long LL;

const int N = 2e3 + 5;

int n, fa[N], c[N], rt, sz[N], num[N], idx, v[N];

vector<int> s[N], g[N];

bool vis[N];

bool cmp(int x, int y) {
	return v[x] < v[y];
}

void dfs(int u) {
	if (!g[u].size()) {
		
		v[u] = (++idx) * (n + 1);
	//cout << u << " fzhi " << v[u] << endl;
		return;
	}
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		dfs(v);
	}
	sort(s[u].begin(), s[u].end(), cmp);
//	puts("SR");
//	for (int i = 0; i < s[u].size(); i++) {
//		cout << " upd " << u << " " << s[u][i] << " " << v[s[u][i]] << endl;
//	}
	if (c[u] == s[u].size()) {
	//	cout << " haha for " << u << endl;
		v[u] = v[s[u].back()] + 1;
		//cout << v[u] << " ?//\n";
		return;
		//idx = v[u];
	}
	v[u] = v[s[u][c[u]]];
	for (int i = c[u]; i < s[u].size(); i++) {
		v[s[u][i]]++;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", fa + i, c + i);
		if (!fa[i]) rt = i;
		else g[fa[i]].pb(i);		
	}
	for (int i = 1; i <= n; i++) {
		int p = fa[i];
		while (p) {
			sz[p]++;
			s[p].pb(i);
			p = fa[p];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (c[i] > sz[i]) {
			puts("NO");
			return 0;
		}
	}
	dfs(rt);
	puts("YES");
	for (int i = 1; i <= n; i++) printf("%d ", v[i]);
	return 0;
}