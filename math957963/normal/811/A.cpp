#include<cstdio>
int main(void){
	int a, b;
	scanf("%d %d", &a, &b);
	for (int i = 0;; i++){
		a = a - (2*i) - 1;
		if (a < 0){
			printf("Vladik\n");
			return 0;
		}
		b = b - (2 * i) - 2;
		if (b < 0){
			printf("Valera\n");
			return 0;
		}
	}
	return 0;
}