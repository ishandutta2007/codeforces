#include<cstdio>
int g(int x, int y) {
	return y ? g(y, x%y) : x;
}
int main() {
	int A, B, x;
	scanf("%d%d", &A, &B);int C = B;
	while (A--) {
		scanf("%d", &x);
		C = g(C, x);
	}
	printf("%d\n0", B / C);
	for (int i = C; i < B; i += C)
		printf(" %d", i);
	puts("");
	return 0;
}