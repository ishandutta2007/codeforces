#include <cstdio>
#include <cstring>
const int dx[4] = {0, 0, 1, 1}, dy[4] = {0, 1, 0, 1};

int n, m;
char str[60][60];
bool vis[30];

int main(){
	int i, j, k, ans = 0;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; ++ i)
		scanf("%s", str[i] + 1);
	for(i = 1; i < n; ++ i)
		for(j = 1; j < m; ++ j){
			memset(vis, 0, sizeof(vis));
			for(k = 0; k < 4; ++ k)
				vis[str[i + dx[k]][j + dy[k]] - 'a'] = true;
			if(vis['f' - 'a'] && vis[0] && vis['c' - 'a'] && vis['e' - 'a']) ans ++;
		}
	printf("%d\n", ans);
	return 0;
}