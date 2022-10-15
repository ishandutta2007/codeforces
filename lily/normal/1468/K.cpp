#include <bits/stdc++.h>
using namespace std;
#define N 5055

const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};
char s[N];
int xx[N], yy[N], d[N];
void work() {
	scanf("%s", s + 1);
	int n= (int)strlen(s + 1);
	for (int i = 1; i <= n; i++) {
		switch (s[i]) {
			case 'L' : d[i] = 0; break;
			case 'R' : d[i] = 1; break;
			case 'U' : d[i] = 2; break;
			case 'D' : d[i] = 3; break;
		}
	}
	for (int i = 1; i <= n; i++) {
		xx[i] = xx[i - 1] + dx[d[i]];
		yy[i] = yy[i - 1] + dy[d[i]];
	}
	if (yy[n] == xx[n] && xx[n] == 0) {
		puts("1000000000 1000000000");
		return;
	}
	for (int i = 1; i <= n; i++ ){
		if (xx[i] != 0 || yy[i] != 0) {
			int x = 0, y = 0, bx = xx[i], by = yy[i];
			for (int j = 1; j <= n; j++) {
				int tx = x + dx[d[j]];
				int ty = y + dy[d[j]];
				if (tx != bx || ty != by) {
					x = tx;
					y = ty;
				}
			}
			if (x == 0 && y == 0) {
				printf("%d %d\n", bx, by);
				return;
			}
		}
	}
	puts("0 0");
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--) work();

}