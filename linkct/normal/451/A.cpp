#include <stdio.h>
inline int min(int a, int b){return a > b ? b : a;}
int main()
{
	int t1, t2;
	scanf("%d%d", &t1, &t2);
	printf("%s\n", min(t1, t2) % 2 ? "Akshat" : "Malvika");
	return 0;
}