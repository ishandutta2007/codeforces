#include <cstdio>

int n, m; char str[200005];

int main(){
	int i; str[0] = '0';
	scanf("%d%d%s", &n, &m, str + 1);
	for(i = 1; str[i] != '.'; ++ i) ;
	for(++ i; str[i] && str[i] <= '4'; ++ i) ;
	if(!str[i]){
		printf("%s\n", str + 1);
		return 0;
	}
	for(; str[i] >= '5' && m --; -- i){
		str[i] = 0;
		if(str[i - 1] == '.'){
			++ str[i - 2];
			str[i - 1] = 0;
			for(i -= 2; str[i] > '9'; ++ str[-- i])
				str[i] -= 10;
			if(!i){
				printf("%s\n", str);
				return 0;
			} break;
		}else ++ str[i - 1];
	}
	printf("%s\n", str + 1);
	return 0;
}