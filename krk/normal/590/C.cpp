#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 100000000;
const int Maxn = 1005;
const int Maxd = 3;
const int Maxc = 4;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

int n, m;
char B[Maxn][Maxn];
int dist[Maxd][Maxn][Maxn];
int res = Inf;

void Calc(int id, int dist[][Maxn])
{
	fill((int*)dist, (int*)dist + Maxn * Maxn, Inf);
	deque <ii> Q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (B[i][j] == '1' + id) {
				Q.push_back(ii(i, j)); dist[i][j] = 0;
			}
	while (!Q.empty()) {
		ii v = Q.front(); Q.pop_front();
		int d = dist[v.first][v.second];
		for (int i = 0; i < Maxc; i++) {
			ii u = ii(v.first + dy[i], v.second + dx[i]);
			if (0 <= u.first && u.first < n && 0 <= u.second && u.second < m && B[u.first][u.second] != '#')
				if (B[u.first][u.second] == '.') {
					if (d + 1 < dist[u.first][u.second]) {
						dist[u.first][u.second] = d + 1; Q.push_back(u);
					}
				} else if (d < dist[u.first][u.second]) {
					dist[u.first][u.second] = d; Q.push_front(u);
				}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", B[i]);
	for (int i = 0; i < Maxd; i++)
		Calc(i, dist[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) if (B[i][j] != '#')
			if (B[i][j] == '.') res = min(res, dist[0][i][j] + dist[1][i][j] + dist[2][i][j] - 2);
			else res = min(res, dist[0][i][j] + dist[1][i][j] + dist[2][i][j]);
	printf("%d\n", res == Inf? -1: res);
	return 0;
}