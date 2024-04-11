#include <cstdio>
#include <cctype>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000000;
const int Maxn = 11;
const int MaxN = 205;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n, t;
char a[Maxn][Maxn], b[Maxn][Maxn];
int br, bc;
int bum[Maxn][Maxn];
int dist[Maxn][Maxn];
bool pos[Maxn][Maxn];
int N;
int R[MaxN][MaxN];
vector <int> neigh[MaxN];
int F[MaxN], P[MaxN];
int res;

void BFS1()
{
	fill((int*)bum, (int*)bum + Maxn * Maxn, t); bum[br][bc] = 0;
	queue <ii> Q; Q.push(ii(br, bc));
	while (!Q.empty()) {
		ii v = Q.front(); int d = bum[v.first][v.second]; Q.pop();
		for (int i = 0; i < Maxd; i++) {
			ii u = ii(v.first + dy[i], v.second + dx[i]);
			if (0 <= u.first && u.first < n && 0 <= u.second && u.second < n && a[u.first][u.second] != 'Y' && d + 1 < bum[u.first][u.second])
				bum[u.first][u.second] = d + 1, Q.push(u);
		}
	}
}

void BFS2(int sr, int sc)
{
	fill((int*)dist, (int*)dist + Maxn * Maxn, Inf); dist[sr][sc] = 0;
	fill((bool*)pos, (bool*)pos + Maxn * Maxn, false); pos[sr][sc] = true;
	queue <ii> Q; Q.push(ii(sr, sc));
	while (!Q.empty()) {
		ii v = Q.front(); int d = dist[v.first][v.second]; Q.pop();
		pos[v.first][v.second] = d <= bum[v.first][v.second];
		if (d >= bum[v.first][v.second]) continue;
		for (int i = 0; i < Maxd; i++) {
			ii u = ii(v.first + dy[i], v.second + dx[i]);
			if (0 <= u.first && u.first < n && 0 <= u.second && u.second < n && a[u.first][u.second] != 'Y' && d + 1 < dist[u.first][u.second])
				dist[u.first][u.second] = d + 1, Q.push(u);
		}
	}
}

void BFS(int sr, int sc, int dist[][Maxn], int Inf)
{
	fill((int*)dist, (int*)dist + Maxn * Maxn, Inf); dist[sr][sc] = 0;
	queue <ii> Q; Q.push(ii(sr, sc));
	while (!Q.empty()) {
		ii v = Q.front(); int d = dist[v.first][v.second]; Q.pop();
		for (int i = 0; i < Maxd; i++) {
			ii u = ii(v.first + dy[i], v.second + dx[i]);
			if (0 <= u.first && u.first < n && 0 <= u.second && u.second < n && a[u.first][u.second] != 'Y' && d + 1 < dist[u.first][u.second])
				dist[u.first][u.second] = d + 1, Q.push(u);
		}
	}
}

int getFlow()
{
	fill(F, F + N, 0); F[0] = Inf;
	priority_queue <ii> Q; Q.push(ii(Inf, 0));
	while (!Q.empty()) {
		int v = Q.top().second, f = Q.top().first; Q.pop();
		if (F[v] != f) continue;
		for (int i = 0; i < neigh[v].size(); i++) {
			int u = neigh[v][i];
			if (min(f, R[v][u]) > F[u]) F[u] = min(f, R[v][u]), P[u] = v, Q.push(ii(F[u], u));
		}
	}
	int v = N - 1;
	if (F[v] == 0) return 0;
	int res = F[v];
	while (v) {
		int u = P[v];
		R[u][v] -= res; R[v][u] += res;
		v = u;
	}
	return res;
}

int main()
{
	scanf("%d %d", &n, &t);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf(" %c", &a[i][j]);
			if (a[i][j] == 'Z') { br = i; bc = j; }
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf(" %c", &b[i][j]);
	BFS1();
	N = 2 * n * n + 2;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) if (isdigit(a[i][j]) && a[i][j] > '0') {
			int v = i * n + j + 1; R[0][v] = a[i][j] - '0'; neigh[0].push_back(v); neigh[v].push_back(0);
			BFS2(i, j);
			for (int i2 = 0; i2 < n; i2++)
				for (int j2 = 0; j2 < n; j2++) if (pos[i2][j2] && isdigit(b[i2][j2]) && b[i2][j2] > '0') {
					int u = n * n + i2 * n + j2 + 1; R[v][u] = Inf; neigh[v].push_back(u); neigh[u].push_back(v);
				}
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) if (isdigit(b[i][j]) && b[i][j] > '0') {
			int u = n * n + i * n + j + 1; R[u][N - 1] = b[i][j] - '0'; neigh[u].push_back(N - 1); neigh[N - 1].push_back(u);
		}
	int f;
	while ((f = getFlow()) != 0) res += f;
	printf("%d\n", res);
	return 0;
}