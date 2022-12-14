#include <cstdio>
const int MAXN = 100005;

int n, prime[MAXN], pcnt;
bool isComp[MAXN];

int main(){
	int i, j; bool two = false;
	scanf("%d", &n); ++ n;
	for(i = 2; i <= n; ++ i){
		if(!isComp[i]){
			prime[++ pcnt] = i;
			if(2 * i <= n) two = true;
		}
		for(j = 1; i * prime[j] <= n; ++ j){
			isComp[i * prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
	if(two){
		printf("2\n");
		for(i = 2; i <= n; ++ i) printf("%d ", isComp[i] ? 2 : 1);
	}else{
		printf("1\n");
		for(i = 2; i <= n; ++ i) printf("1 ");
	} return 0;
}