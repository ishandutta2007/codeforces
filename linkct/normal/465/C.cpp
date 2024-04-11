#include <cstdio>

int len, sigma;
char str[1005];

int main(){
	int i;
	scanf("%d%d%s", &len, &sigma, str + 1);
	for(i = len; i && str[i] - 'a' + 1 == sigma; -- i);
	if(!i){
		printf("NO\n");
		return 0;
	}
	str[i] ++;
	while(i <= len){
		if((i > 1 && str[i] == str[i - 1]) || (i > 2 && str[i] == str[i - 2])){
			while(i && str[i] - 'a' + 1 == sigma) -- i;
			if(!i){
				printf("NO\n");
				return 0;
			}
			str[i] ++;
		}else str[++ i] = 'a';
	}
	str[len + 1] = 0;
	printf("%s\n", str + 1);
	return 0;
}