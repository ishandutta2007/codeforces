#include <bits/stdc++.h>
#define broken cerr << "running on " << __FUNCTION__ <<" "<< __LINE__ << endl
#define x first
#define y second
#define mp make_pair
#define sz(a) int((a).size())
#define par pair<int, int>
#define poly vector<int>
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int N = 2e5 + 10;
int n, m, q, ans = 0;
set<int> g[N];

void change(int u, int t) {
	ans += t * (*(--g[u].end()) < u);
	return;
}

void ins(int u, int v) {
	change(u, -1), change(v, -1);
	g[u].insert(v), g[v].insert(u);
	change(u, 1), change(v, 1);
}

void del(int u, int v) {
	change(u, -1), change(v, -1);
	g[u].erase(v), g[v].erase(u);
	change(u, 1), change(v, 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) g[i].insert(0);
	ans = n;
	for(int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		ins(u, v);
	}
	cin >> q;
	for(int i = 1; i <= q; i++) {
		int opt, u, v;
		cin >> opt;
		if(opt <= 2) {
			cin >> u >> v;
			if(opt == 1) ins(u, v);
			else del(u, v);
		} else cout << ans << endl;
	}
    return 0;
}