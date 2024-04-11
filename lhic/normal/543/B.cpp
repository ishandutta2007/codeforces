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

const int MAXN = 4000;

int n, m;
vector<int> eds[MAXN];
int dd[MAXN];
int ss[2][MAXN];
int tt[2][MAXN];

int s[2];
int t[2];
int l[2];

void bfs(int v) {
	for (int i = 0; i < n; ++i)
		dd[i] = 100000;
	dd[v] = 0;
	queue<int> qq;
	qq.push(v);
	while (!qq.empty()) {
		int x = qq.front();
		qq.pop();
		for (int i = 0; i < (int)eds[x].size(); ++i) {
			int u = eds[x][i];
			if (dd[u] > dd[x] + 1)
				dd[u] = dd[x] + 1, qq.push(u);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	cin >> s[0] >> t[0] >> l[0]	>> s[1] >> t[1] >> l[1];

	--s[0], --t[0], --s[1], --t[1];
	for (int i = 0; i < 2; ++i) {
		bfs(s[i]);
		memcpy(ss[i], dd, sizeof(dd[0]) * n);
		bfs(t[i]);
		memcpy(tt[i], dd, sizeof(dd[0]) * n);
	}
	if (ss[0][t[0]] > l[0]) {
		cout << -1;
		return 0;
	}
	if (ss[1][t[1]] > l[1]) {
		cout << -1;
		return 0;
	}

	int ans = max(0, m - ss[0][t[0]] - ss[1][t[1]]);

	for (int i = 0; i < n; ++i) {
		bfs(i);
		for (int j = 0; j < n; ++j) {
			if (ss[0][i] + dd[j] + tt[0][j] <= l[0] && ss[1][i] + dd[j] + tt[1][j] <= l[1])
				ans = max(ans, m - ss[0][i] - ss[1][i] - tt[0][j] - tt[1][j] - dd[j]);
			if (ss[0][i] + dd[j] + tt[0][j] <= l[0] && ss[1][j] + dd[j] + tt[1][i] <= l[1])
				ans = max(ans, m - ss[0][i] - ss[1][j] - tt[0][j] - tt[1][i] - dd[j]);
		}
	}
	cout << ans;

	return 0;
}