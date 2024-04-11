#include <cstdio>

int main(){
	int n, k, i;
	scanf("%d%d", &n, &k);
	printf("%d\n", (6 * n - 1) * k);
	for(i = 0; i < n; ++ i)
		printf("%d %d %d %d\n", (6 * i + 1) * k, (6 * i + 2) * k, (6 * i + 3) * k, (6 * i + 5) * k);
	return 0;
}