#include<cstdio>
int main(void){
	int n;
	int a[10];
	int x = 0;
	int z = 0;
	scanf("%d", &n);
	while (n % 10 == 0)n = n / 10;
	for (x = 0; n != 0; x++){
		a[x] = n % 10;
		n = n / 10;
	}
	for (int i = 0; i<x / 2; i++){
		if (a[i] != a[x - i - 1])z = 1;
	}
	if (z == 0)printf("YES\n");
	else printf("NO\n");
	return 0;
}