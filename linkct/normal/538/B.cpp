#include <cstdio>
#include <cstring>

int n;
char str[10], buf[10];

int main(){
	int i, ans = 0, j;
	scanf("%s", str + 1);
	n = strlen(str + 1);
	for(i = 1; i <= n; ++ i){
		str[i] -= '0';
		if(str[i] > ans) ans = str[i];
	}
	printf("%d\n", ans);
	for(i = 1; i <= ans; ++ i){
		for(j = 1; j <= n; ++ j)
			if(str[j]) buf[j] = 1, str[j] --;
			else buf[j] = 0;
		for(j = 1; j <= n; ++ j)
			if(buf[j]) break;
		for(; j <= n; ++ j)
			putchar(buf[j] + '0');
		printf(" ");
	}
	printf("\n");
	return 0;
}