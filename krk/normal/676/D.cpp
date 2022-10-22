#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

const int Maxn = 1005;
const int Maxd = 4;
const int dy[Maxd] = {0, 1, 0, -1};
const int dx[Maxd] = {-1, 0, 1, 0};
const int D[Maxd] = {1 << 0, 1 << 1, 1 << 2, 1 << 3};
const int Inf = 1000000000;

struct pos {
	int r, c, a;
	pos(int r = 0, int c = 0, int a = 0): r(r), c(c), a(a) {}
};

int n, m;
int B[Maxn][Maxn];
int dist[Maxn][Maxn][Maxd];
int xs, ys;
int xe, ye;

bool Pass(int r, int c, int p, int a)
{
	return B[r][c] & 1 << ((p + a) % Maxd);
}

int getMask(char ch)
{
	if (ch == '+') return D[0] | D[1] | D[2] | D[3];
	if (ch == '-') return D[0] | D[2];
	if (ch == '|') return D[1] | D[3];
	if (ch == '^') return D[3];
	if (ch == '>') return D[2];
	if (ch == '<') return D[0];
	if (ch == 'v') return D[1];
	if (ch == 'L') return D[1] | D[2] | D[3];
	if (ch == 'R') return D[0] | D[1] | D[3];
	if (ch == 'U') return D[0] | D[1] | D[2];
	if (ch == 'D') return D[0] | D[2] | D[3];
	return 0;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			char ch; scanf(" %c", &ch);
			B[i][j] = getMask(ch);
		}
	scanf("%d %d", &xs, &ys);
	scanf("%d %d", &xe, &ye);
	fill((int*)dist, (int*)dist + Maxn * Maxn * Maxd, Inf); dist[xs][ys][0] = 0;
	queue <pos> Q; Q.push(pos(xs, ys, 0));
	while (!Q.empty()) {
		pos v = Q.front(); Q.pop();
		int d = dist[v.r][v.c][v.a];
		if (v.r == xe && v.c == ye) { printf("%d\n", d); return 0; }
		pos u = pos(v.r, v.c, (v.a + 1) % Maxd);
		if (d + 1 < dist[u.r][u.c][u.a]) {
			dist[u.r][u.c][u.a] = d + 1;
			Q.push(u);
		}
		for (int i = 0; i < Maxd; i++) {
			pos u = pos(v.r + dy[i], v.c + dx[i], v.a);
			if (1 <= u.r && u.r <= n && 1 <= u.c && u.c <= m &&
				Pass(v.r, v.c, i, v.a) && Pass(u.r, u.c, (i + 2) % Maxd, u.a) &&
				d + 1 < dist[u.r][u.c][u.a]) {
				dist[u.r][u.c][u.a] = d + 1;
				Q.push(u);
			}
		}
	}
	printf("-1\n");
	return 0;
}