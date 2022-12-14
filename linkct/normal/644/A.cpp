#include <cstdio>

int main(){
	int i, j, n, a, b, cnt = 0, val[105];
	scanf("%d%d%d", &n, &a, &b);
	if(a * b < n){
		printf("-1\n");
		return 0;
	}
	for(i = 1; i <= a; ++ i){
		for(j = 1; j <= b; ++ j) val[j] = cnt < n ? (++ cnt) : 0;
		if((b & 1) || (i & 1))
			for(j = 1; j <= b; ++ j)
				printf("%d%c", val[j], j == b ? '\n' : ' ');
		else for(j = b; j; -- j)
			printf("%d%c", val[j], j == 1 ? '\n' : ' ');
	}
	return 0;
}