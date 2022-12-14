#include <cstdio>
const int MAXN = 105;

int n, m, w[MAXN][MAXN], ans;
char str[MAXN];

void add(int x, int y, int v){
	if(!v) return;
	ans ++;
	int i, j;
	for(i = x; i; -- i)
		for(j = y; j; -- j)
			w[i][j] -= v;
}
int main(){
	int i, j;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; ++ i){
		scanf("%s", str + 1);
		for(j = 1; j <= m; ++ j)
			w[i][j] = str[j] == 'W' ? 1 : -1;
	}
	for(i = n; i; -- i)
		for(j = m; j; -- j)
			add(i, j, w[i][j]);
	printf("%d\n", ans);
	return 0;
}