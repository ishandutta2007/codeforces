#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <tuple>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	// q1 is the unique number that appears only once
	// we then also know that the other two are back-to-back
	// Add an edge between them, we now know they are adjacent

	vector<set<int>> apps(n);
	vector<tuple<int, int, int>> pol(n-2);
	for (int i = 0; i < n-2; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		--a; --b; --c;
		pol[i] = tie(a, b, c);

		apps[a].insert(i);
		apps[b].insert(i);
		apps[c].insert(i);
	}
	vector<int> q, ans;
	for (int i = 0; i < n; ++i) {
		if (apps[i].size() == 1) q.push_back(i);
	}

	vector<int> le(n, -1), ri(n, -1);
	for (int j = 0; j < n-2; ++j) {
		int x = q[j];
		int i = *apps[x].begin();
		ans.push_back(i);

		int y, z, tmp;
		tie(y, z, tmp) = pol[i];
		if (y == x) swap(y, z);
		if (z == x) swap(z, tmp);
		le[x] = y;
		ri[x] = z;

		apps[x].erase(i);
		apps[y].erase(i);
		apps[z].erase(i);
		if (apps[y].size() == 1) q.push_back(y);
		if (apps[z].size() == 1) q.push_back(z);

		if (j == n-3) {
			le[y] = z;
			le[z] = x;
			ri[y] = x;
			ri[z] = y;
		}
	}
	
	for (int j = n-4; j >= 0; --j) {
		int x = q[j];
		if (ri[le[x]] != ri[x]) swap(le[x], ri[x]);
		ri[le[x]] = x;
		le[ri[x]] = x;
	}

	vector<int> p(n, -1);
	int c = 0;
	for (int i = 0; i < n; ++i) {
		p[i] = c;
		c = ri[c];
	}

	for (auto v : p) cout << v+1 << ' '; cout << '\n';
	for (auto v : ans) cout << v+1 << ' '; cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}