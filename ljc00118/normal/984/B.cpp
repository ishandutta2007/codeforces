#include<bits/stdc++.h>
using namespace std;

const int N = 100 + 10;

char c[N][N];
int mx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int my[8] = {1, 0, -1, 1, -1, 1, 0, -1};
int n, m;

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%s", c[i] + 1);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(c[i][j] != '*') {
				int tmp = 0;
				for(int k = 0; k < 8; k++) {
					int x = i + mx[k], y = j + my[k];
					if(x <= 0 || y <= 0 || x > n || y > m) continue;
					if(c[x][y] == '*') tmp++;
				}
				if(c[i][j] == '.') {
					if(tmp != 0) {
						printf("NO");
						return 0;
					}
				}
				else {
					if(tmp != c[i][j] - '0') {
						printf("NO");
						return 0;
					}
				}
			}
		}
	}
	printf("YES");
	return 0;
}