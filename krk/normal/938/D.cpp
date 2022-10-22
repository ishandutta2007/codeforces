#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, ll> ill;
typedef pair <ll, int> lli;

const ll Inf = 4000000000000000000ll;
const int Maxn = 200005;

int n, m;
vector <ill> neigh[Maxn];
ll dist[Maxn];

int main()
{
	fill(dist, dist + Maxn, Inf);
	scanf("%d %d", &n, &m);
	while (m--) {
		int v, u; ll w; scanf("%d %d %I64d", &v, &u, &w);
		neigh[v].push_back(ill(u, w));
		neigh[u].push_back(ill(v, w));
	}
	priority_queue <lli> Q;
	for (int i = 1; i <= n; i++) {
		scanf("%I64d", &dist[i]);
		Q.push(lli(-dist[i], i));
	}
	while (!Q.empty()) {
		int v = Q.top().second; ll d = -Q.top().first; Q.pop();
		if (dist[v] != d) continue;
		for (int i = 0; i < neigh[v].size(); i++) {
			ill u = neigh[v][i];
			if (d + 2 * u.second < dist[u.first]) {
				dist[u.first] = d + 2 * u.second;
				Q.push(lli(-dist[u.first], u.first));
			}
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%I64d%c", dist[i], i + 1 <= n? ' ': '\n');
	return 0;
}