#include <cstdio>
int main(){
	char str[105];
	int n, i;
	scanf("%d%s", &n, str + 1);
	for(i = 1; i <= n && str[i] == '1'; ++ i);
	if(i == n + 1)
		printf("%d\n", n);
	else printf("%d\n", i);
	return 0;
}