#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1005;
int n, m, k, ans[N][N], sum = 0;
char g[N][N];
bool st[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void dfs(int x, int y) {
	st[x][y] = true;
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if(nx < 1 || nx > n || ny < 1 || ny > m || st[nx][ny]) continue;
		if(g[nx][ny] == '*') sum++;
		else dfs(nx, ny);
	}
}
void fold(int x, int y) {
	ans[x][y] = sum;
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if(nx < 1 || nx > n || ny < 1 || ny > m || ans[nx][ny]) continue;
		if(g[nx][ny] == '.') fold(nx, ny);
	}
}
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%s", g[i] + 1);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(!st[i][j] && g[i][j] == '.') {
				sum = 0; 
				dfs(i, j);
				fold(i, j);
			}
		}
	}
	while(k--) {
		int x, y; scanf("%d%d", &x, &y);
		printf("%d\n", ans[x][y]);
	}
	return 0;
}