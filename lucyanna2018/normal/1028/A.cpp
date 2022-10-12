#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

int row, col;char s[999];
int minx, miny, maxx, maxy;
int main() {
	scanf("%d%d", &row, &col);
	minx = 999, miny = 999; maxx = -1, maxy = -1;
	for (int i = 1; i <= row; i++) {
		scanf("%s", s+1);
		for (int j = 1; j <= col; j++) {
			if (s[j] == 'B') {
				minx = min(minx, i);
				miny = min(miny, j);
				maxx = max(maxx, i);
				maxy = max(maxy, j);
			}
		}
	}
	printf("%d %d\n", (minx + maxx) / 2, (miny + maxy) / 2);
	return 0;
}