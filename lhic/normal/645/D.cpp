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

int was[MAXN];
vector<int> vv;
int cnt[MAXN];
int n, m;
int go[MAXN];
vector<pair<int, int> > ed;
vector<int> eds[MAXN];

void dfs(int v) {
	was[v] = 1;
	for (int u: eds[v])
		if (!was[u])
			dfs(u);
	vv.push_back(v);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		ed.push_back(make_pair(a, b));
		eds[a].push_back(b);
	}
	for (int i = 0; i < n; ++i)
		if (!was[i])
			dfs(i);
	reverse(vv.begin(), vv.end());
	for (int i = 0; i < (int)vv.size(); ++i)
		go[vv[i]] = i;
	int now = 0;
	for (int i = 0; i < m; ++i) {
		int a, b;
		a = ed[i].first;
		b = ed[i].second;
		a = go[a];
		if (a < n - 1 && b == vv[a + 1] && cnt[a] == 0)
			cnt[a] = 1, ++now;
		if (now == n - 1) {
			cout << i + 1 << "\n";
			return 0;
		}
	}
	cout << -1 << "\n";
	return 0;
}