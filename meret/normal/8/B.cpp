#include <cstdio>

int vis[300][300];

int a = 150;

char s[120];

int main() {
	int x = a, y = a;
	scanf("%s", s);
	vis[x][y] = 1;
	for (int i = 0; s[i]; ++i) {
		if (s[i] == 'L') --x;
		else if (s[i] == 'R') ++x;
		else if (s[i] == 'D') ++y;
		else --y;
		int cnt = vis[x][y] + vis[x - 1][y] + vis[x + 1][y] + vis[x][y - 1] + vis[x][y + 1];
		if (cnt > 1) {
			printf("BUG\n");
			return 0;
		}
		vis[x][y] = 1;
	}
	printf("OK\n");
}