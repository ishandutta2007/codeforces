#include <cstdio>
const int MAXN = 105;

int f[MAXN][MAXN], n, m, q;

int find(int f[], int x){
	return f[x] == x ? x : f[x] = find(f, f[x]);
}
void merge(int f[], int a, int b){
	f[find(f, a)] = find(f, f[b]);
}
int main(){
	int a, b, c, i, j, ans;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; ++ i)
		for(j = 1; j <= m; ++ j)
			f[j][i] = i;
	for(i = 1; i <= m; ++ i){
		scanf("%d%d%d", &a, &b, &c);
		if(find(f[c], a) != find(f[c], b))
			merge(f[c], a, b);
	}
	scanf("%d", &q);
	for(i = 1; i <= q; ++ i){
		scanf("%d%d", &a, &b);
		for(j = 1, ans = 0; j <= m; ++ j)
			if(find(f[j], a) == find(f[j], b))
				ans ++;
		printf("%d\n", ans);
	}
	return 0;
}