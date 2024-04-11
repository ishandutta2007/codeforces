#include <stdio.h>
inline bool isdigit(char x){return x >= '0' && x <= '9';}
int main()
{
	int a[5], ans;
	char ch;
	scanf("%d%d%d%d", &a[1], &a[2], &a[3], &a[4]);
	while(!isdigit(ch = getchar()));
	ans = a[ch - '0'];
	while(isdigit(ch = getchar()))
		ans += a[ch - '0'];
	printf("%d\n", ans);
	return 0;
}