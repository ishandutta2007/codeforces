#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int Q = 100005;

int n, m, q;
int now[N][N];
int ans[Q];
int cur;
int op[Q], x[Q], y[Q];
vector<int> go[Q];

void modify(int &nw,int val) {
	cur -= nw;
	nw = val;
	cur += nw;
}

void dfs(int u) {
	int save = -1;
	if (op[u] == 1) {
		save = now[x[u]][y[u]];
		modify(now[x[u]][y[u]], 1);
	} else if (op[u] == 2) {
		save = now[x[u]][y[u]];
		modify(now[x[u]][y[u]], 0);
	} else if (op[u] == 3) {
		for (int y = 1; y <= m; ++y) {
			modify(now[x[u]][y], now[x[u]][y] ^ 1);
		}
	}
	ans[u] = cur;
	for (int v : go[u]) {
		dfs(v);
	}
	if (op[u] == 1 || op[u] == 2) {
		modify(now[x[u]][y[u]], save);
	} else if (op[u] == 3) {
		for (int y = 1; y <= m; ++y) {
			modify(now[x[u]][y], now[x[u]][y] ^ 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m >> q;
	for (int i = 1; i <= q; ++i) {
		cin >> op[i];
		if (op[i] == 4) {
			int pr;
			cin >> pr;
			go[pr].push_back(i);
		} else {
			go[i - 1].push_back(i);
			cin >> x[i];
			if (op[i] <= 2) {
				cin >> y[i];
			}
		}
	} 
	dfs(0);
	for (int i = 1; i <= q; ++i) {
		cout << ans[i] << '\n';
	}
}