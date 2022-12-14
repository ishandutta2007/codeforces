#include <cstdio>

int n, k, h[105], op[1005][2], minh, maxh, minpos, maxpos;

int main(){
	int i, j, cnt = 0;
	scanf("%d%d", &n, &k);
	for(i = 1; i <= n; ++ i)
		scanf("%d", &h[i]);
	for(i = 1; i <= k; ++ i){
		minh = 10005, maxh = 0;
		for(j = 1; j <= n; ++ j){
			if(h[j] < minh){
				minh = h[j];
				minpos = j;
			}
			if(h[j] > maxh){
				maxh = h[j];
				maxpos = j;
			}
		}
		if(minh == maxh || maxh == minh + 1) break;
		cnt ++;
		op[cnt][0] = maxpos;
		op[cnt][1] = minpos;
		h[maxpos] --, h[minpos] ++;
	}
	minh = 10005, maxh = 0;
	for(j = 1; j <= n; ++ j){
		if(h[j] < minh){
			minh = h[j];
			minpos = j;
		}
		if(h[j] > maxh){
			maxh = h[j];
			maxpos = j;
		}
	}
	printf("%d %d\n", maxh - minh, cnt);
	for(i = 1; i <= cnt; ++ i)
		printf("%d %d\n", op[i][0], op[i][1]);
	return 0;
}