#include <cstdio>

int n; char str[200005];

int main(){
	int i, ans = 0;
	scanf("%d%s", &n, str + 1);
	for(i = 1; str[i] == '<'; ++ i, ++ ans) ;
	for(i = n; str[i] == '>'; -- i, ++ ans) ;
	printf("%d\n", ans);
	return 0;
}