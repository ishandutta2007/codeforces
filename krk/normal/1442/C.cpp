#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;
typedef pair <ii, ii> iiii;

const int mod = 998244353;
const int Maxn = 200005;
const int Maxm = 19;
const int Inf = 1000000000;

int n, m;
vector <int> neigh[2][Maxn];
ii dist[Maxn][2];
int D[Maxn][Maxm];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[0][a].push_back(b);
		neigh[1][b].push_back(a);
	}
	fill((ii*)dist, (ii*)dist + Maxn * 2, ii(Inf, Inf));
	dist[1][0] = ii(0, 0);
	priority_queue <iiii> Q1; Q1.push(iiii(ii(-dist[1][0].first, -dist[1][0].second), ii(1, 0)));
	while (!Q1.empty()) {
		ii v = Q1.top().second;
		ii d = Q1.top().first; Q1.pop();
		d = ii(-d.first, -d.second);
		if (dist[v.first][v.second] != d) continue;
		ii u = ii(v.first, 1 - v.second);
		ii cand = ii(d.first + 1, d.second);
		if (cand < dist[u.first][u.second]) {
			dist[u.first][u.second] = cand;
			Q1.push(iiii(ii(-cand.first, -cand.second), u));
		}
		for (int i = 0; i < neigh[v.second][v.first].size(); i++) {
			u = ii(neigh[v.second][v.first][i], v.second);
			cand = ii(d.first, d.second + 1);
			if (cand < dist[u.first][u.second]) {
				dist[u.first][u.second] = cand;
				Q1.push(iiii(ii(-cand.first, -cand.second), u));
			}
		}
	}
	ii ans = min(dist[n][0], dist[n][1]);
	if (ans.first >= 18) {
		int res = 1;
		for (int i = 0; i < ans.first; i++)
			res = 2ll * res % mod;
		res = (res - 1 + mod) % mod;
		res = (res + ans.second) % mod;
		printf("%d\n", res);
		return 0;
	}
	fill((int*)D, (int*)D + Maxn * Maxm, Inf);
	D[1][0] = 0;
	deque <iii> Q; Q.push_back(iii(0, ii(1, 0)));
	while (!Q.empty()) {
		ii v = Q.front().second;
		int d = Q.front().first; Q.pop_front();
		if (D[v.first][v.second] != d) continue;
		if (v.second + 1 < Maxm) {
			ii u = ii(v.first, v.second + 1);
			if (d < D[u.first][u.second]) {
				D[u.first][u.second] = d;
				Q.push_front(iii(d, u));
			}
		}
		int st = v.second % 2;
		for (int i = 0; i < neigh[st][v.first].size(); i++) {
			ii u = ii(neigh[st][v.first][i], v.second);
			if (d + 1 < D[u.first][u.second]) {
				D[u.first][u.second] = d + 1;
				Q.push_back(iii(d + 1, u));
			}
		}
	}
	int res = Inf;
	for (int i = 0; i < Maxm; i++) if (D[n][i] < Inf) {
		int cand = 1;
		for (int j = 0; j < i; j++)
			cand *= 2;
		cand--;
		cand += D[n][i];
		res = min(res, cand);
	}
	printf("%d\n", res);
    return 0;
}