#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> g[605];
int par[605], color[605];
bool inPath[605];
vector<int> had[605];

int ask(vector<int> ver,char t) {
	if (ver.empty()) return 0;
	cout << t << ' ' << ver.size() << '\n';
	for (int v : ver) cout << v << ' '; cout << '\n';
	if (t == '?') {
		int x; cin >> x;
		return x;
	}
	exit(0);
}

int calc(int u, vector<int> ver) {
	int x = ask(ver, '?');
	ver.push_back(u);
	int y = ask(ver, '?');
	return y - x;
}

void buildST() {
	for (int i = 1; i <= n; ++i) color[i] = -1;
	queue<int> q;
	color[1] = 0; q.push(1);
	had[0].push_back(1);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		vector<int> ver;
		for (int i = 1; i <= n; ++i) {
			if (color[i] == -1) ver.push_back(i);
		}
		int cnt = calc(u, ver);
		for (int it = 1; it <= cnt; ++it) {
			int low = 0, high = ver.size() - 1;
			while (low < high) {
				int mid = (low + high) >> 1;
				int cur = calc(u, vector<int>(ver.begin(), ver.begin() + mid + 1));
				if (cur >= it) high = mid;
				else low = mid + 1;
			}
			int v = ver[low];
			color[v] = color[u] ^ 1;
			g[u].push_back(v);
			g[v].push_back(u);
			had[color[v]].push_back(v);
			q.push(v);
		}
	}
}

void dfs(int u,int p,int target) {
	if (u == target) {
		inPath[u] = 1;
		return;
	}
	for (int v : g[u]) if (v != p) {
		dfs(v, u, target);
		inPath[u] |= inPath[v];
	} 
}

void go(int u,int p,vector<int> &path) {
	path.push_back(u);
	for (int v : g[u]) if (v != p && inPath[v]) {
		go(v, u, path);
	}
}

void tracePath(int u,int v) {
	dfs(u, -1, v);
	vector<int> path;
	go(u, -1, path);
	ask(path, 'N'); 
}

void checkSide(vector<int> ver) {
	if (ask(ver, '?') == 0) return;
	int low = 0, high = ver.size() - 1;
	while (low < high) {
		int mid = (low + high) >> 1;
		int cur = ask(vector<int>(ver.begin(), ver.begin() + mid + 1), '?');
		if (cur > 0) high = mid;
		else low = mid + 1;
	}
	int u = ver[low];
	int pos = low;
	low = 0, high--;
	while (low < high) {
		int mid = (low + high) >> 1;
		int cur = calc(u, vector<int>(ver.begin(), ver.begin() + mid + 1));
		if (cur > 0) high = mid;
		else low = mid + 1;
	}
	int v = ver[low];
	tracePath(u, v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	buildST();
	checkSide(had[0]);
	checkSide(had[1]);
	ask(had[0], 'Y');
}