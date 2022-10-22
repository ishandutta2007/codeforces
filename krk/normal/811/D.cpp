#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 105;
const int Maxd = 4;
const int dy[Maxd] = {0, -1, 0, 1};
const int dx[Maxd] = {-1, 0, 1, 0};
char sym[Maxd] = {'L', 'U', 'R', 'D'};
bool ok[Maxd] = {false, false, false, false};

int n, m;
char B[Maxn][Maxn];
int fx, fy;
bool tk[Maxn][Maxn];
int par[Maxn][Maxn];

ii Move(char ch)
{
	printf("%c\n", ch); fflush(stdout);
	int x, y; scanf("%d %d", &x, &y);
	return ii(x, y);
}

void Solve()
{
	tk[fx][fy] = true;
	queue <ii> Q; Q.push(ii(fx, fy));
	while (!Q.empty()) {
		ii v = Q.front(); Q.pop();
		for (int i = 0; i < Maxd; i++) {
			ii u = ii(v.first + dy[i], v.second + dx[i]);
			if (1 <= u.first && u.first <= n && 1 <= u.second && u.second <= m && B[u.first][u.second] != '*' && !tk[u.first][u.second]) {
				tk[u.first][u.second] = true; par[u.first][u.second] = (i + 2) % Maxd;
				Q.push(u);
			}
		}
	}
}

void Traverse()
{
	ii cur = ii(1, 1);
	while (cur.first != fx || cur.second != fy) {
		int my = par[cur.first][cur.second];
		if (!ok[my]) {
			ii nxt = Move(sym[my]);
			ok[my] = ok[(my + 2) % Maxd] = true;
			if (nxt == cur) { swap(sym[my], sym[(my + 2) % Maxd]); continue; }
			cur = nxt;
		} else cur = Move(sym[my]);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &B[i][j]);
			if (B[i][j] == 'F') fx = i, fy = j;
		}
	Solve();
	Traverse();
	return 0;
}