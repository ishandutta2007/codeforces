#include <cstdio>

inline int max(int a, int b){return a > b ? a : b;}
int main(){
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	if((a <= c && b <= d) || (a + b <= max(c, d)))
		printf("Polycarp\n");
	else printf("Vasiliy\n");
	return 0;
}