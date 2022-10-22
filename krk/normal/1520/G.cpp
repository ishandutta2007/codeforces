#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ii> llii;

const int Maxn = 2003;
const int Inf = 1000000000;
const ll bInf = 1000000000000000000ll;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n, m, w;
int A[Maxn][Maxn];
int dist1[Maxn][Maxn];
int dist2[Maxn][Maxn];

void BFS(int r, int c, int dist[][Maxn])
{
	fill((int*)dist, (int*)dist + Maxn * Maxn, Inf);
	dist[r][c] = 0;
	vector <ii> Q; Q.push_back(ii(r, c));
	for (int z = 0; z < Q.size(); z++) {
		ii v = Q[z];
		for (int i = 0; i < Maxd; i++) {
			ii u = ii(v.first + dy[i], v.second + dx[i]);
			if (0 <= u.first && u.first < n && 0 <= u.second && u.second < m &&
				A[u.first][u.second] != -1) {
				int cand = dist[v.first][v.second] + 1;
				if (cand < dist[u.first][u.second]) {
					dist[u.first][u.second] = cand;
					Q.push_back(u);
				}
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &w);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &A[i][j]);
	BFS(0, 0, dist1);
	BFS(n - 1, m - 1, dist2);
	ll res = dist1[n - 1][m - 1] < Inf? ll(dist1[n - 1][m - 1]) * w: bInf;
	ll res1 = bInf, res2 = bInf;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) if (A[i][j] > 0) {
			if (dist1[i][j] < Inf) res1 = min(res1, ll(dist1[i][j]) * w + A[i][j]);
			if (dist2[i][j] < Inf) res2 = min(res2, ll(dist2[i][j]) * w + A[i][j]);
		}
	res = min(res, res1 + res2);
	printf("%I64d\n", res >= bInf? -1ll: res);
    return 0;
}