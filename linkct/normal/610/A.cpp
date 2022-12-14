#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	if(n & 1) printf("0\n");
	else printf("%d\n", (n >> 2) - (n % 4 ? 0 : 1));
	return 0;
}