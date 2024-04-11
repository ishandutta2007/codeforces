#include <cstdio>

int main(){
	int n, i;
	scanf("%d", &n);
	printf("2\n");
	for(i = 2; i <= n; ++ i)
		printf("%I64d\n", i * (long long int)(i + 1) * (i + 1) - i + 1);
	return 0;
}