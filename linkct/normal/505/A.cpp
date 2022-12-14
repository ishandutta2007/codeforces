#include <cstdio>
#include <cstring>

int len; char init[15], buf[15];

bool test(int pos, char val){
	int i;
	for(i = 1, buf[0] = 0; i <= pos; ++ i)
		buf[++ buf[0]] = init[i];
	buf[++ buf[0]] = val;
	for(; i <= len; ++ i)
		buf[++ buf[0]] = init[i];
	buf[++ buf[0]] = 0;
	for(i = 1; i <= (len + 1) >> 1; ++ i)
		if(buf[i] != buf[len + 2 - i]) return false;
	return true;
}
int main(){
	int i, j;
	scanf("%s", init + 1);
	len = strlen(init + 1);
	for(i = 0; i <= len; ++ i)
		for(j = 'a'; j <= 'z'; ++ j)
			if(test(i, (char)j)){
				printf("%s\n", buf + 1);
				return 0;
			}
	printf("NA\n");
	return 0;
}