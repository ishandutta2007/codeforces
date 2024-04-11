#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> data;
#define fi first
#define se second
#define pb push_back

const int N = 4e5 + 5;

int n, d, k;
vector<ii> edges;
priority_queue<data> pq;
int deg[N], far[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> d >> k;
	if (k == 1 && n > 2) return cout << "NO\n",0;
	if (n <= d) return cout << "NO\n",0; 
	for (int i = 1; i <= d; ++i) {
		deg[i]++, deg[i + 1]++;
		edges.pb(ii(i, i + 1));
		far[i] = max(i - 1, d + 1 - i);
	}
	far[d + 1] = d;
	int tot = d + 1;
	for (int i = 1; i <= d + 1; ++i) {
		if (deg[i] < k && far[i] < d) pq.push(data(ii(far[i], deg[i]), i));
	}
	while (!pq.empty()) {
		if (tot == n) break;
		int u = pq.top().se; pq.pop();
		tot++; edges.pb(ii(u, tot));
		deg[u]++; if (deg[u] < k) pq.push(data(ii(far[u], deg[u]), u));
		deg[tot]++; far[tot] = far[u] + 1;
		if (deg[tot] < k && far[tot] < d) pq.push(data(ii(far[tot], deg[tot]), tot));
	}
	if (tot < n) return cout << "NO\n",0;
	cout << "YES\n";
	for (auto edge : edges) {
		cout << edge.fi << ' ' << edge.se << '\n';
	}
}