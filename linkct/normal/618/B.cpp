#include <cstdio>

int n, a[55][55], p[55];

int extract(int id){
	int ret = 0, i;
	for(i = 1; i <= n; ++ i){
		if(!a[i][id]) continue;
		if(ret && a[i][id] != ret) return 0;
		ret = a[i][id];
	}
	for(i = 1; i <= n; ++ i){
		if(!a[id][i]) continue;
		if(ret && a[id][i] != ret) return 0;
		ret = a[id][i];
	}
	return ret;
}
int main(){
	int i, j, k, tmp;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i)
		for(j = 1; j <= n; ++ j)
			scanf("%d", &a[i][j]);
	for(i = 1; i < n; ++ i){
		for(j = 1; j <= n; ++ j)
			if(tmp = extract(j)) break;
		p[j] = tmp;
		for(k = 1; k <= n; ++ k)
			a[k][j] = a[j][k] = 0;
	}
	for(i = 1; i <= n; ++ i) printf("%d ", p[i] ? p[i] : n);
	return 0;
}