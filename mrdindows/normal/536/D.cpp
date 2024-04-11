#include <cstdio>
#include <vector>
#include <queue>
#include <cassert>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 2005;
const ll Inf = 1000000000000000000ll;

int n, m;
int s, t;
int p[Maxn];
vector <ii> neigh[Maxn];
ll dists[Maxn], distt[Maxn];
vector <ll> unx, uny;
int rowc[Maxn][Maxn], colc[Maxn][Maxn];
ll rows[Maxn][Maxn], cols[Maxn][Maxn];
ll dp1[Maxn][Maxn][2], dp2[Maxn][Maxn][2];

void Dijkstra(int v, ll dist[])
{
	fill(dist, dist + n + 1, Inf); dist[v] = 0;
	priority_queue <lli> Q; Q.push(lli(-dist[v], v));
	while (!Q.empty()) {
		int v = Q.top().second; ll d = -Q.top().first; Q.pop();
		if (d != dist[v]) continue;
		for (int i = 0; i < neigh[v].size(); i++) {
			ii u = neigh[v][i];
			if (d + u.second < dist[u.first]) {
				dist[u.first] = d + u.second;
				Q.push(lli(-dist[u.first], u.first));
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	scanf("%d %d", &s, &t);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	while (m--) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		neigh[a].push_back(ii(b, c));
		neigh[b].push_back(ii(a, c));
	}
	Dijkstra(s, dists); Dijkstra(t, distt);
	for (int i = 1; i <= n; i++) {
		unx.push_back(dists[i]);
		uny.push_back(distt[i]);
	}
	sort(unx.begin(), unx.end()); unx.erase(unique(unx.begin(), unx.end()), unx.end());
	sort(uny.begin(), uny.end()); uny.erase(unique(uny.begin(), uny.end()), uny.end());

	for (int i = 1; i <= n; i++) {
		int x = lower_bound(unx.begin(), unx.end(), dists[i]) - unx.begin() + 1;
		int y = lower_bound(uny.begin(), uny.end(), distt[i]) - uny.begin() + 1;
		rowc[y][x]++; colc[x][y]++;
		rows[y][x] += p[i]; cols[x][y] += p[i];
	}

	for (int i = 0; i <= unx.size(); i++)
		for (int j = 1; j <= uny.size(); j++) {
			colc[i][j] += colc[i][j - 1];
			cols[i][j] += cols[i][j - 1];
		}
	for (int j = 0; j <= uny.size(); j++)
		for (int i = 1; i <= unx.size(); i++) {
			rowc[j][i] += rowc[j][i - 1];
			rows[j][i] += rows[j][i - 1];
		}

	for (int i = unx.size(); i >= 0; i--)
		for (int j = uny.size(); j >= 0; j--)
			for (int k = 0; k < 2; k++) {
				if (i == unx.size()) dp1[i][j][k] = 0;
				else {			
					ll sum = cols[i + 1][uny.size()] - cols[i + 1][j];
					int cnt = colc[i + 1][uny.size()] - colc[i + 1][j];
					int nk = k || cnt > 0;
					dp1[i][j][k] = sum + dp1[i + 1][j][nk];
				}

				if (j == uny.size()) dp2[i][j][k] = 0;
				else {
					ll sum = rows[j + 1][unx.size()] - rows[j + 1][i];
					int cnt = rowc[j + 1][unx.size()] - rowc[j + 1][i];
					int nk = k || cnt > 0;
					dp2[i][j][k] = sum + dp2[i][j + 1][nk];
				}

				if (k) {
					dp1[i][j][1] = max(dp1[i][j][1], -dp2[i][j][0]);
					dp2[i][j][1] = max(dp2[i][j][1], -dp1[i][j][0]);
				}
			}
	if (dp1[0][0][0] > 0) printf("Break a heart\n");
	else if (dp1[0][0][0] < 0) printf("Cry\n");
	else printf("Flowers\n");
	return 0;
}