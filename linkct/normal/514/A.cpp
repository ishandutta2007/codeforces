#include <cstdio>

char str[20];

int main(){
	scanf("%s", str);
	int i;
	for(i = 0; str[i]; ++ i)
		if(str[i] > '9' - str[i] + '0'){
			str[i] = '9' - str[i] + '0';
			if(!i && str[i] == '0') str[i] = '9';
		}
	printf("%s\n", str);
	return 0;
}