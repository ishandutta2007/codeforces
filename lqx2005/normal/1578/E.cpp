#include <bits/stdc++.h>
#define broken cerr << "running on " << __FUNCTION__ <<" "<< __LINE__ << endl
#define x first
#define y second
#define sz(a) int((a).size())
#define pi pair<int, int>
#define i64 long long
#define u64 unsigned long long
#define db double
using namespace std;
const int N = 2000 + 10;
int n, c[N], siz[N], a[N];
vector<int> g[N], s[N];

int dfs(int u) {
	siz[u] = 1;
	int res = 1;
	for(int &v : g[u]) {
		res &= dfs(v);
		siz[u] += siz[v];
	}
	if(c[u] > siz[u] - 1) res = 0;
	return res;
}

void DFS(int u) {
	for(int &v : g[u]) {
		DFS(v);
		s[u].insert(s[u].end(), s[v].begin(), s[v].end());
	}
	s[u].insert(s[u].begin() + c[u], u);
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int p;
		cin >> p >> c[i];
		g[p].push_back(i);
	}
	int rt = g[0][0];
	if(!dfs(rt)) return cout << "NO" << endl, 0;
	DFS(rt);
	for(int i = 0; i < sz(s[rt]); i++) a[s[rt][i]] = i + 1;
	cout << "YES" << endl;
	for(int i = 1; i <= n; i++) cout << a[i] <<" ";
	cout << endl;
	return 0;
}