#include <bits/stdc++.h>
#define sz(a) int((a).size())
using namespace std;
typedef long long i64;
const int N = 1e6 + 10;
vector<int> g[N];
int fa[N];
int n, q, a[N], p[N], vis[N], tot = 0;
set<int> s[N];

int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]); }

int unite(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return 0;
	return fa[x] = y, 1;
}

void sieve(int n) {
	vis[0] = vis[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(!vis[i]) p[++tot] = i, g[i].push_back(i);
		for(int j = 1; j <= tot && i * p[j] <= n; j++) {
			vis[i * p[j]] = 0;
			g[i * p[j]] = g[i];
			g[i * p[j]].push_back(p[j]);
			if(i % p[j] == 0) break;
		}
	}
	return;
}

int main() {
	sieve(N - 9);
	cin >> n >> q;
	for(int i = 1; i <= tot; i++) fa[p[i]] = p[i];
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < sz(g[a[i]]); j++) {
			unite(g[a[i]][j - 1], g[a[i]][j]);
		}
	}
	for(int i = 1; i <= n; i++) {
		vector<int> div;
		for(int j = 0; j < sz(g[a[i] + 1]); j++) {
			div.push_back(find(g[a[i] + 1][j]));
		}
		div.push_back(find(g[a[i]][0]));
		sort(div.begin(), div.end());
		div.erase(unique(div.begin(), div.end()), div.end());
		for(int j = 0; j < sz(div); j++) {
			for(int k = j + 1; k < sz(div); k++) {
				s[div[j]].insert(div[k]);
			}
		}
	}
	int x, y;
	for(int i = 1; i <= q; i++) {
		cin >> x >> y;
		x = find(g[a[x]][0]), y = find(g[a[y]][0]);
		if(x > y) swap(x, y);
		if(x == y) {
			cout << 0 << endl;
		} else if(s[x].count(y)){
			cout << 1 << endl;
		} else {
			cout << 2 << endl;
		}
	}
	return 0;
}