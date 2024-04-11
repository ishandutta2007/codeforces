#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define x first
#define y second
#define sz(a) (int)a.size()
const int N = 2e5 + 100;
const int mod = 1e9 + 7;
vector <pair <int, int> > g[N];
int h[N];

int dsu[N];
int rang[N];

int pred(int a) {
	if (a == dsu[a]) {
		return a;
	}
	return dsu[a] = pred(dsu[a]);
}

void unite(int a, int b) {
	a = pred(a);
	b = pred(b);
	if (a == b) {
		return;
	}
	if (rang[a] > rang[b]) {
		swap(a, b);
	}
	dsu[b] = a;
	rang[a] += rang[b];
}

void dfs(int v, int p = -1) {
	for (auto to : g[v]) {
		if (to.x == p) {
			continue;
		}
		if (to.y == -1) {
			h[to.x] = h[v];
		}
		else {
			h[to.x] = h[v] ^ to.y;
		}
		dfs(to.x, v);
	}
}
int get_cnt(int a) {
	int cnt = 0;
	while (a > 0) {
		cnt += a & 1;
		a /= 2;
	}
	return cnt;
}


int used[N];
int colored[N];
void dfs1(int v, int color) {
	used[v] = 1;
	colored[v] = color;
	for (auto to : g[v]) {
		if (used[to.x] || to.y == -1) {
			continue;
		}
		dfs1(to.x, color);
	}
}

int used1[N];
int colored1[N];
vector <int> g1[N];

bool dfs2(int v, int color) {
	used1[v] = 1;
	colored1[v] = color;
	for (auto to : g1[v]) {
		if (!used1[to]) {
			if(!dfs2(to, 1 - color)) {
				return false;
			}
		}
		else if(colored1[to] == colored1[v]) {
			return false;
		}
	}
	return true;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			dsu[i] = i;
			rang[i] = 1;
		}
		vector <vector <int> > pr;
		for (int i = 0; i < n - 1; i++) {
			int x, y, w;
			cin >> x >> y >> w;
			x--;
			y--;
			pr.push_back({x, y, w});
			g[x].push_back({y, w});
			g[y].push_back({x, w});
		}
		dfs(0);
		vector <vector <int> > queries;
	/*	for (int i = 0; i < n; i++) {
			cout << h[i] << " ";
		}
		cout << "\n";
	*/	while (m--) {
			int a, b, p;
			cin >> a >> b >> p;
			a--;
			b--;
			int val = h[a] ^ h[b];
			if (get_cnt(val) % 2 != p) {
				queries.push_back({a, b, 1});
			}
			else {
				queries.push_back({a, b, 0});
			}
		}
		int c1 = 0;
		for (int i = 0; i < n; i++) {
			if (!used[i]) {
				dfs1(i, c1++);
			}
		}
	/*	for (int i = 0; i < n; i++) {
			cout << colored[i] << " ";
		}
		cout << "\n";
	*/	for (auto query : queries) {
		//	cout << "A " << colored[query[0]] << " " << colored[query[1]]<< " " << query[2] << "\n";
			if (query[2] == 0) {
				unite(colored[query[0]], colored[query[1]]);
			}
		}
	//	cout << "\n";
		int fl = 1;
		for (auto query : queries) {
			if (query[2] == 1) {
				int u = pred(colored[query[0]]);
				int v = pred(colored[query[1]]);
				if (u == v) {
					fl = 0;
					break;
				}
		//		cout << "D " << u << " " << v << "\n";
				g1[u].push_back(v);
				g1[v].push_back(u);
			}
		}
		if (fl) {
			for (int i = 0; i < c1; i++) {
				if (!used1[i] && !dfs2(i, 0)) {
					fl = 0;
					break;
				} 
			}
		}
		if (fl) {
			cout << "YES\n";
			for (int i = 0; i < n - 1; i++) {
				cout << pr[i][0] + 1 << " " << pr[i][1] + 1 << " ";
				if (pr[i][2] == -1) {
					int a = pred(colored[pr[i][0]]);
					int b = pred(colored[pr[i][1]]);
					if (colored1[a] != colored1[b]) {
						cout << 1 << "\n";
					}
					else {
						cout << 0 << "\n";
					}
				}
				else {
					cout << pr[i][2] << "\n";
				}
			}
		}
		else {
			cout << "NO\n";
		}
		for (int i = 0; i < n; i++) {
			used[i] = used1[i] = 0;
			colored[i] = colored1[i] = 0;
			g1[i].clear();
			g[i].clear();
		}
	}
	return 0;
}