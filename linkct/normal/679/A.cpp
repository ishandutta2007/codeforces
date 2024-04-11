#include <cstdio>

bool iscomp[105]; int res[105], prime[105], pcnt; char buf[15];

int main(){
	int i, j, cnt = 0;
	for(i = 2; i <= 50; ++ i){
		if(iscomp[i]) continue;
		prime[++ pcnt] = i;
		for(j = i * 2; j <= 50; j += i)
			iscomp[j] = true;
	}
	for(i = 1; i <= 15; ++ i){
		printf("%d\n", prime[i]);
		fflush(stdout);
		scanf("%s", buf);
		if(buf[0] == 'y') res[i] = 1, ++ cnt;
	}
	if(cnt > 1){
		printf("composite\n");
		fflush(stdout);
		return 0;
	}
	for(i = 1; i <= 4; ++ i)
		if(res[i]) break;
	if(i > 4){
		printf("prime\n");
		fflush(stdout);
		return 0;
	}
	printf("%d\n", prime[i] * prime[i]);
	fflush(stdout);
	scanf("%s", buf);
	printf("%s\n", buf[0] == 'y' ? "composite" : "prime");
	fflush(stdout);
	return 0;
}