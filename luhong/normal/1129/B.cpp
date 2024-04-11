#include <cstdio>

int main()
{
	int n = 2000;
	int k; scanf("%d", &k);
	int lst = n - k % n;
	int a = lst + 998000;
	int b = a - (k + a) / n;
	puts("2000");
	for(int i = 1; i <= 1998; i++) printf("0 ");
	printf("%d %d\n", -b, a);
}

//00000000 b a (b<0, a>0)
//k+a
//b = (k+a) / (0+2) - a
//0+2 = 2000  a