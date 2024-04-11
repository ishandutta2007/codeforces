#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int sg[42][42][42][42][2];
int h, w;
char g[42][42];
 
int calc(int x1, int x2, int y1, int y2, int d) {
	if (x1 > x2 || y1 > y2) return 0;
	if (sg[x1][x2][y1][y2][d] != -1) return sg[x1][x2][y1][y2][d];
	int &v = sg[x1][x2][y1][y2][d];
	v = 0;
	set<int> s;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++) 
			if (i + j >= x1 && i + j <= x2 && i + (w - j - 1) >= y1
				&& i + (w - j - 1) <= y2 && (i + j) % 2 == d) {
				int x = i + j, y = i + (w - j - 1);
				if (g[i][j] == 'L') {
					s.insert(calc(x1, x - 1, y1, y2, d) ^
						calc(x + 1, x2, y1, y2, d));
				} else if (g[i][j] == 'R') {
					s.insert(calc(x1, x2, y1, y - 1, d) ^
						calc(x1, x2, y + 1, y2, d));
				} else {
					s.insert(calc(x1, x - 1, y1, y - 1, d) ^
						calc(x + 1, x2, y1, y - 1, d) ^ 
						calc(x1, x - 1, y + 1, y2, d) ^
						calc(x + 1, x2, y + 1, y2, d));
				}
			}
	while (s.count(v)) v++;
	return v;
}
 
int main() {
	memset(sg, -1, sizeof(sg));
	scanf("%d%d", &h, &w);
	for (int i = 0; i < h; i++) {
		scanf("%s", g[i]);
	}
	// i + j, i + (w - j - 1)
	puts((calc(0, h + w - 2, 0, h + w - 2, 0) ^
		calc(0, h + w - 2, 0, h + w - 2, 1))?"WIN":"LOSE");
}