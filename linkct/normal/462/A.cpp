#include <cstdio>
const int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
char g[105][105];
int n;
bool inmap(int x, int y){return x >= 1 && x <= n && y >= 1 && y <= n;}
int main(){
	int i, j, k, tmp;
	bool sign = false;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i)
		scanf("%s", g[i] + 1);
	for(i = 1; i <= n; ++ i)
		for(j = 1; j <= n; ++ j){
			tmp = 0;
			for(k = 0; k < 4; ++ k)
				if(inmap(i + dx[k], j + dy[k]))
					tmp += g[i + dx[k]][j + dy[k]] == 'o' ? 1 : 0;
			if(tmp % 2)
				sign = true;
		}
	printf("%s\n", sign ? "NO" : "YES");
	return 0;
}