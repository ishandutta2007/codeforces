#include <cstdio>
using namespace std;

const int Maxd = 4;
const int dy[Maxd] = {0, 1, 0, -1};
const int dx[Maxd] = {1, 0, -1, 0};
const int add[Maxd] = {1, 0, 1, 0};

int x, y;
int curx, cury;
int res;
int len = 1, ang;

int main()
{
	scanf("%d %d", &x, &y);
	while (x != curx || y != cury) {
		for (int i = 0; i < len && (x != curx || y != cury); i++) {
			curx += dx[ang]; cury += dy[ang];
		}
		if (x == curx && y == cury) break;
		res++;
		ang = (ang + 1) % Maxd; len += add[ang];
	}
	printf("%d\n", res);
	return 0;
}