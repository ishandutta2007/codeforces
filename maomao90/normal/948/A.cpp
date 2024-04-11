#include <bits/stdc++.h>
using namespace std;

int dirr[] = {0, 1, 0, -1}, dirc[] = {1, 0, -1, 0};

int r, c;
char grid[505][505];

int main() {
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) 
		scanf(" %c", &grid[i][j]);
	for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) {
		if (grid[i][j] == 'W') {
			for (int k = 0; k < 4; k++) {
				int vr = i + dirr[k], vc = j + dirc[k];
				if (vr >= r || vr < 0 || vc >= c || vc < 0) continue;
				if (grid[vr][vc] == 'S') {
					printf("NO\n");
					return 0;
				}
				if (grid[vr][vc] == '.') grid[vr][vc] = 'D';
			}
		}
	}
	printf("YES\n");
	for (int i = 0; i < r; i++) {
		printf("%s\n", grid[i]);
	}
	return 0;
}