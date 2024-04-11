#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>

using namespace std;

vector<vector<int> > v;
vector<bool> was;
int q = true;

int dfs(int ver, int val) {
	if (was[ver])
		return 0;
	if (v[ver].size() != val)
		q = false;
	was[ver] = true;
	int res = 1;
	for (auto x : v[ver])
		res += dfs(x, val);
	return res;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	v.assign(n, vector<int>());
	was.assign(n, false);
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		v[l].push_back(r);
		v[r].push_back(l);
	}
	for (int i = 0; i < n; i++) {
		if (was[i])
			continue;
		if (dfs(i, v[i].size()) - 1 != v[i].size())
			q = false;
	}
	cout << (q ? "YES" : "NO") << endl;
	return 0;
}