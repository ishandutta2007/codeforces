#include <bits/stdc++.h>
using namespace std;

using ll = long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 300000;
int n, m, x[N], y[N], u, v, vis[N];
ll ans[N];
vector<int> e[N];

struct people {
	int x, y;
	int id;
} p[N];

bool operator < (people a, people b) {
	return a.y - a.x < b.y - b.x;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x[i], &y[i]);
		p[i] = (people) {x[i], y[i], i};
	}
	sort(p, p + n);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);
		--u; --v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	ll sumy = 0;
	ll sumx = 0;
	for (int i = 0; i < n; i++) sumx += x[i];
	for (int i = 0; i < n; i++) {
		int z = p[i].id;
		ll x1 = sumy, x2 = sumx - x[z];
		int y1 = i, y2 = n - i - 1;
		for (auto p : e[z]) {
			if (vis[p]) x1 -= y[p], y1--;
			else {
				x2 -= x[p];
				y2--;
			}
		}
		ans[z] = x1 + (ll) y1 * x[z] + x2 + (ll) y2 * y[z];
		vis[z] = 1;
		sumy += y[z];
		sumx -= x[z];
	}
	for (int i = 0; i < n; i++) {
		printf("%lld%c", ans[i], (i == n - 1) ? '\n' : ' ');
	}
}