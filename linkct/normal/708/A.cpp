#include <cstdio>

char str[100005];

int main(){
	int i;
	scanf("%s", str + 1);
	for(i = 1; str[i] == 'a'; ++ i) ;
	if(!str[i]){
		str[i - 1] = 'z';
		printf("%s\n", str + 1);
		return 0;
	}
	for(; str[i] && str[i] != 'a'; ++ i) -- str[i];
	printf("%s\n", str + 1);
	return 0;
}