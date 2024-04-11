#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 100 * 1000 + 10;

vector<int> g[N];
set<int> col[N];
int c[N];
int root = -1;

void dfs1(int v, int par) {
	col[v].insert(c[v]);
	for (int to : g[v]) 
		if (to != par) {
			dfs1(to, v);
			for (int x : col[to])
				col[v].insert(x);
			while (col[v].size() > 2)
				col[v].erase(col[v].begin());
		}
}

void dfs2(int v, int par, int lowCol) {
	bool ok = true;
	for (int to : g[v])
		if (to != par) 
			if (col[to].size() > 1)
				ok = false;
	if (ok) {
		root = v;
		return;
	}
	if (lowCol != c[v])
		return;
	vector<int> bad;
	for (int to : g[v])
		if (to != par && (c[to] != lowCol || col[to].size() > 1))
			bad.push_back(to);
	assert (bad.size());
	if (bad.size() > 1)
		return;
	dfs2(bad[0], v, lowCol);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
		cin >> c[i];
	dfs1(0, 0);
	dfs2(0, 0, c[0]);
	if (root == -1)
		cout << "NO" << endl;
	else
		cout << "YES" << endl << root + 1 << endl;
}