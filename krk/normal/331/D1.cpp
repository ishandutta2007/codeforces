#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

struct pos {
	int x, y, d;
	pos(int x = 0, int y = 0, int d = 0): x(x), y(y), d(d) { }
};

const int Maxn = 31;
const int Maxk = 55;
const int Maxd = 4;
const int dx[Maxd] = {0, 1, 0, -1};
const int dy[Maxd] = {-1, 0, 1, 0};
const string dstr = "DRUL";

int n, b;
pos nxt[Maxn][Maxn][Maxd][Maxk];
int q;

void Next(int x, int y, int d, int wh)
{
	pos xyd = pos(x + dx[wh], y + dy[wh], wh);
	if (xyd.x < 0 || xyd.x > b || xyd.y < 0 || xyd.y > b) nxt[x][y][d][0] = pos(-1, -1, -1);
	else nxt[x][y][d][0] = xyd;
}

pos getPos(int x, int y, int d, ll t)
{
	pos p = pos(x, y, d);
	for (int i = Maxk - 1; i >= 0; i--) if (1ll << i <= t && nxt[p.x][p.y][p.d][i].x != -1) {
		p = nxt[p.x][p.y][p.d][i]; t -= 1ll << i;
	}
	return p;
}

int main()
{
	scanf("%d %d", &n, &b);
	for (int i = 0; i <= b; i++)
		for (int j = 0; j <= b; j++)
			for (int d = 0; d < Maxd; d++)
				Next(i, j, d, d);
	while (n--) {
		int x1, y1, x2, y2; scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		if (x1 == x2)
			if (y1 < y2)
				for (int h = y1; h <= y2; h++)
					for (int d = 0; d < Maxd; d++) Next(x1, h, d, 2);
			else for (int h = y1; h >= y2; h--)
					for (int d = 0; d < Maxd; d++) Next(x1, h, d, 0);
		else if (x1 < x2)
				for (int w = x1; w <= x2; w++)
					for (int d = 0; d < Maxd; d++) Next(w, y1, d, 1);
			else for (int w = x1; w >= x2; w--)
					for (int d = 0; d < Maxd; d++) Next(w, y1, d, 3);
	}
	for (int k = 1; k < Maxk; k++)
		for (int i = 0; i <= b; i++)
			for (int j = 0; j <= b; j++)
				for (int d = 0; d < Maxd; d++)
					if (nxt[i][j][d][k - 1].x == -1) nxt[i][j][d][k] = nxt[i][j][d][k - 1];
					else {
						pos p = nxt[i][j][d][k - 1];
						nxt[i][j][d][k] = nxt[p.x][p.y][p.d][k - 1];
					}
	scanf("%d", &q);
	while (q--) {
		int x, y; char d; ll t; scanf("%d %d %c %I64d", &x, &y, &d, &t);
		pos p = getPos(x, y, dstr.find(d), t);
		printf("%d %d\n", p.x, p.y);
	}
	return 0;
}