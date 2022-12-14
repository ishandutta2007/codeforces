#include <cstdio>
#include <cstring>
const char* match = "CODEFORCES";

int n;
char str[105];

inline bool check(int pos){
	char buf[20]; int i, len = 0;
	for(i = 1; i < pos; ++ i)
		buf[len ++] = str[i];
	for(i = pos + n - 10; i <= n; ++ i)
		buf[len ++] = str[i];
	buf[len] = 0;
	return !strcmp(buf, match);
}
int main(){
	int i;
	scanf("%s", str + 1);
	n = strlen(str + 1);
	if(n <= 10){
		printf("NO\n");
		return 0;
	}
	for(i = 1; i <= 11; ++ i)
		if(check(i)){
			printf("YES\n");
			return 0;
		}
	printf("NO\n");
	return 0;
}