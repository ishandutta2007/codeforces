#include <cstdio>
#include <cstring>

char str1[105], str2[105];

int main(){
	int i, len;
	scanf("%s%s", str1, str2);
	len = strlen(str1);
	i = len - 1;
	while(i > 0 && str1[i] == 'z') i --;
	if(str1[i] == 'z'){
		printf("No such string\n");
		return 0;
	}
	str1[i] ++;
	for(++ i; i < len; ++ i)
		str1[i] = 'a';
	for(i = 0; i < len; ++ i)
		if(str1[i] != str2[i]){
			printf("%s\n", str1);
			return 0;
		}
	printf("No such string\n");
	return 0;
}