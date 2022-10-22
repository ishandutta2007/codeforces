#include <bits/stdc++.h>
using namespace std;

const int Maxd = 4;
const int Inf = 1005;

int X1[Maxd], Y1[Maxd];
int X2[Maxd], Y2[Maxd];
int x1, y1, x2, y2;
int x3, y3, x4, y4;

int main()
{
	x1 = y1 = x3 = y3 = Inf;
	x2 = y2 = x4 = y4 = -Inf;
	for (int i = 0; i < Maxd; i++) {
		scanf("%d %d", &X1[i], &Y1[i]); X1[i] *= 2; Y1[i] *= 2;
		x1 = min(x1, X1[i]); x2 = max(x2, X1[i]);
		y1 = min(y1, Y1[i]); y2 = max(y2, Y1[i]);
	}
	for (int i = 0; i < Maxd; i++) {
		scanf("%d %d", &X2[i], &Y2[i]); X2[i] *= 2; Y2[i] *= 2;
		x3 = min(x3, X2[i] - Y2[i]); x4 = max(x4, X2[i] - Y2[i]);
		y3 = min(y3, X2[i] + Y2[i]); y4 = max(y4, X2[i] + Y2[i]);
	}
	for (int i = -500; i <= 500; i++)
		for (int j = -500; j <= 500; j++)
			if (x1 <= i && i <= x2 && y1 <= j && j <= y2 &&
				x3 <= i - j && i - j <= x4 && y3 <= i + j && i + j <= y4) {
				printf("YES\n"); return 0;
			}
	printf("NO\n");
	return 0;
}