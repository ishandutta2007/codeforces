#include <cstdio>
#include <algorithm>

using namespace std;

int na, ma, nb, mb;
char a[55][55], b[55][55];
int ans, x, y;

int main() {
	scanf("%d%d", &na, &ma);
	for (int i = 0; i < na; i++) for (int j = 0; j < ma; j++) scanf(" %c", &a[i][j]);
	scanf("%d%d", &nb, &mb);
	for (int i = 0; i < nb; i++) for (int j = 0; j < mb; j++) scanf(" %c", &b[i][j]);
	for (int curx = -max(na, nb); curx <= max(na, nb); curx++) {
		for (int cury = -max(ma, mb); cury <= max(ma, mb); cury++) {
			int cur = 0;
			for (int r = max(0, -curx); r < na; r++) {
				int nr = r + curx;
				if (nr >= nb) break;
				for (int c = max(0, -cury); c < ma; c++) {
					int nc = c + cury;
					if (nc >= mb) break;
					cur += (a[r][c] - '0') * (b[nr][nc] - '0');
				}
			}
			//printf("%d (%d, %d)\n", cur, curx, cury);
			if (cur > ans) {
				x = curx;
				y = cury;
				ans = cur;
			}
		}
	}
	printf("%d %d\n", x, y);
	return 0;
}