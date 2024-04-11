#include <cstdio>

int main(){
	int n, i, cur, val;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &cur);
		while(cur % 2 == 0) cur /= 2;
		while(cur % 3 == 0) cur /= 3;
		if(i == 1) val = cur;
		else if(val != cur){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}