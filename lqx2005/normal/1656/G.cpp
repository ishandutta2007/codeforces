#include <bits/stdc++.h>
#define sz(a) int((a).size())
typedef long long ll;
using namespace std;
const int N = 2e5 + 10;
int n, a[N], p[N], fa[N], q[N];
vector<int> g[N];
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]); }
int merge(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return 0;
	return fa[x] = y, 1;
}
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) g[i].clear(), fa[i] = i, p[i] = q[i] = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		g[a[i]].push_back(i);
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) cnt += (sz(g[i]) & 1);
	if(n & 1) {
		if(cnt > 1) return cout << "NO" << endl, void();
		int x = -1;
		for(int i = 1; i <= n; i++) if(sz(g[i]) & 1) x = i;
		if(a[(n + 1) / 2] == x && sz(g[x]) == 1) {
			cout << "NO" << endl;
			return;
		}
		int v = g[x].back();
		p[v] = (n + 1) / 2;
	} else {
		if(cnt) return cout << "NO" << endl, void();
	}
	int l = 1, r = n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < sz(g[i]); j += 2) {
			p[g[i][j - 1]] = l++, p[g[i][j]] = r--;
		}
	}
	for(int i = 1; i <= n; i++) merge(i, p[i]);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < sz(g[i]); j++) {
			int x = g[i][j - 1], y = g[i][j];
			if(merge(x, y)) swap(p[x], p[y]);
		}
	}
	for(int i = 1; i <= n; i++) q[p[i]] = i;
	for(int i = 2; i <= n / 2; i++) {
		int x = q[i], y = q[n + 1 - i], z = q[i - 1], w = q[n + 1 - (i - 1)];
		if(merge(x, z)) {
			p[x] = i - 1, p[y] = n + 1 - (i - 1), p[z] = n + 1 - i, p[w] = i;
			q[p[x]] = x, q[p[y]] = y, q[p[z]] = z, q[p[w]] = w;
		}
	}
	cout << "YES" << endl;
	for(int i = 1; i <= n; i++) cout << q[i] <<" ";
	cout << endl;
	return;
}
int main() {
	ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	for(cin >> t; t--; ) solve();
	return 0;
}