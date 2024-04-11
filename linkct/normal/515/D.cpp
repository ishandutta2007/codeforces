#include <cstdio>
#include <queue>
using namespace std;
typedef pair <int, int> pii;
const int MAXN = 2005, dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};

int n, m, d[MAXN][MAXN];
char g[MAXN][MAXN], ans[MAXN][MAXN];

int main(){
	queue <pii> q;
	int i, j, cnt = 0, nx, ny;
	pii now;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; ++ i)
		scanf("%s", g[i] + 1);
	for(i = 1; i <= n; ++ i)
		for(j = 1; j <= m; ++ j)
			if(g[i][j] == '.'){
				cnt ++;
				if(g[i + 1][j] == '.') d[i][j] ++, d[i + 1][j] ++;
				if(g[i][j + 1] == '.') d[i][j] ++, d[i][j + 1] ++;
			}
	for(i = 1; i <= n; ++ i)
		for(j = 1; j <= m; ++ j)
			if(d[i][j] == 1) q.push(pii (i, j));
	while(!q.empty()){
		now = q.front();
		q.pop();
		if(d[now.first][now.second] != 1) continue;
		for(i = 0; i < 4; ++ i){
			nx = now.first + dx[i], ny = now.second + dy[i];
			if(g[nx][ny] == '.' && d[nx][ny]){
				switch(i){
					case 0:
						ans[now.first][now.second] = 'v';
						ans[now.first - 1][now.second] = '^';
						break;
					case 1:
						ans[now.first][now.second] = '>';
						ans[now.first][now.second - 1] = '<';
						break;
					case 2:
						ans[now.first][now.second] = '<';
						ans[now.first][now.second + 1] = '>';
						break;
					case 3:
						ans[now.first][now.second] = '^';
						ans[now.first + 1][now.second] = 'v';
						break;
				}
				cnt -= 2;
				for(j = 0; j < 4; ++ j)
					if(g[nx + dx[j]][ny + dy[j]] == '.' && d[nx + dx[j]][ny + dy[j]]){
						d[nx][ny] --;
						d[nx + dx[j]][ny + dy[j]] --;
						if(d[nx + dx[j]][ny + dy[j]] == 1)
							q.push(pii (nx + dx[j], ny + dy[j]));
					}
				break;
			}
		}
	}
	if(cnt) printf("Not unique\n");
	else
		for(i = 1; i <= n; ++ i){
			for(j = 1; j <= m; ++ j)
				if(!ans[i][j]) putchar('*');
				else putchar(ans[i][j]);
			putchar('\n');
		}
	return 0;
}