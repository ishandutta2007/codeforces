#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ii> llii;

const int Maxn = 100005;
const int Maxm = 52;
const ll Inf = 1000000000000000000ll;

int n, m;
vector <ii> neigh[Maxn];
ll dist[Maxn][Maxm];
priority_queue <llii> Q;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		neigh[a].push_back(ii(b, c));
		neigh[b].push_back(ii(a, c));
	}
	fill((ll*)dist, (ll*)dist + Maxn * Maxm, Inf);
	dist[1][0] = 0;
	Q.push(llii(0, ii(1, 0)));
	while (!Q.empty()) {
		ll d = -Q.top().first;
		ii v = Q.top().second; Q.pop();
		if (dist[v.first][v.second] != d) continue;
		if (v.second == 0)
			for (int i = 0; i < neigh[v.first].size(); i++) {
				ii u = neigh[v.first][i];
				if (d < dist[u.first][u.second]) {
					dist[u.first][u.second] = d;
					Q.push(llii(-dist[u.first][u.second], u));
				}
			}
		else for (int i = 0; i < neigh[v.first].size(); i++) {
				ii u = neigh[v.first][i];
				ll cand = d + ll(v.second + u.second) * (v.second + u.second);
				if (cand < dist[u.first][0]) {
					dist[u.first][0] = cand;
					Q.push(llii(-dist[u.first][0], ii(u.first, 0))); 
				}
			}
	}
	for (int i = 1; i <= n; i++)
		printf("%I64d%c", dist[i][0] >= Inf? -1ll: dist[i][0], i + 1 <= n? ' ': '\n');
    return 0;
}