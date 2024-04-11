#include <cstdio>
#include <queue>
#include <algorithm>
#include <cctype>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;
const int Inf = 1000000000;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int r, c;
char B[Maxn][Maxn];
int dist[Maxn][Maxn];
int sr, sc, mr, mc;
int res;

int main()
{
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			scanf(" %c", &B[i][j]);
			if (B[i][j] == 'E') { sr = i; sc = j; }
			else if (B[i][j] == 'S') { mr = i; mc = j; }
		}
	fill((int*)dist, (int*)dist + Maxn * Maxn, Inf); dist[sr][sc] = 0;
	queue <ii> Q; Q.push(ii(sr, sc));
	while (!Q.empty()) {
		ii v = Q.front(); int d = dist[v.first][v.second]; Q.pop();
		for (int i = 0; i < Maxd; i++) {
			ii u = ii(v.first + dy[i], v.second + dx[i]);
			if (0 <= u.first && u.first < r && 0 <= u.second && u.second < c && B[u.first][u.second] != 'T' && d + 1 < dist[u.first][u.second])
				dist[u.first][u.second] = d + 1, Q.push(u);
		}
	}
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (isdigit(B[i][j]) && dist[i][j] <= dist[mr][mc]) res += B[i][j] - '0';
	printf("%d\n", res);
	return 0;
}