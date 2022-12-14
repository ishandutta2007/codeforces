#include <cstdio>

int n;

int main(){
	scanf("%d", &n);
	printf("%d %d\n", (n & 1) ? 9 : 4, (n & 1) ? n - 9 : n - 4);
	return 0;
}