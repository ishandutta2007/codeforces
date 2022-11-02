# include <bits/stdc++.h>
using namespace std;

char s[120][120];
char c[120];
int e[20];
int sx, sy;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

bool go() {
	int x = sx, y = sy;
	for(int i = 0; c[i]; ++i) {
		int k = e[c[i] - '0'];
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(s[nx][ny] == 'E') return true;
		if(s[nx][ny] == '.') x = nx, y = ny;
		else return false;
	}
	return false;
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%s", s[i] + 1);
		for(int j = 1; j <= m; ++j) {
			if(s[i][j] == 'S') {
				sx = i, sy = j, s[i][j] = '.';
			}
		}
	}
	scanf("%s", c);
	for(int i = 0; i < 4; ++i) e[i] = i;
	int ans = 0;
	do {
		ans += go();
	} while(next_permutation(e, e + 4));
	printf("%d\n", ans);
}