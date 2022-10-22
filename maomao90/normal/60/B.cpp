#include <cstdio>
#include <queue>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> iii;

int dirz[] = {1, 0, 0, 0, 0, -1}, dirx[] = {0, 1, 0, -1, 0, 0}, diry[] = {0, 0, 1, 0, -1, 0};

int k, m, n;
char graph[15][15][15];
int x, y;
queue <iii> bfs;
bool visited[15][15][15];
int ans;

int main() {
	scanf("%d%d%d", &k, &n, &m);
	for (int i = 0; i < k; i++) for (int j = 0; j < n; j++) for (int k = 0; k < m; k++)
		scanf(" %c", &graph[i][j][k]);
	scanf("%d%d", &x, &y);
	x--; y--;
	if (graph[0][x][y] == '#') {
        printf("0\n");
        return 0;
	}
	visited[0][x][y] = true;
	bfs.emplace(0, x, y);
	while (!bfs.empty()) {
		int uz, ux, uy; tie(uz, ux, uy) = bfs.front(); bfs.pop();
		for (int i = 0; i < 6; i++) {
			int vz = uz + dirz[i], vx = ux + dirx[i], vy = uy + diry[i];
			if (vz < 0 || vz >= k || vx < 0 || vx >= n || vy < 0 || vy >= m) continue;
			if (graph[vz][vx][vy] == '#' || visited[vz][vx][vy]) continue;
			visited[vz][vx][vy] = true;
			bfs.emplace(vz, vx, vy);
		}
	}
	for (int i = 0; i < k; i++) for (int j = 0; j < n; j++) for (int k = 0; k < m; k++)
		if (visited[i][j][k]) ans++;
	printf("%d\n", ans);
	return 0;
}