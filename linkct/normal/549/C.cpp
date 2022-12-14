#include <cstdio>
const int MAXN = 200005;

int n, k, cnt[2];

//Stannis: 1, Daenerys: 0
//Stannis moves first
inline int min(int a, int b){return a > b ? b : a;}
int main(){
	int i, t;
	scanf("%d%d", &n, &k);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &t);
		cnt[t & 1] ++;
	}
	if(n == k){
		printf("%s\n", (cnt[1] & 1) ? "Stannis" : "Daenerys");
		return 0;
	}
	if((n - k) & 1){//Stannis moves last
		if((k & 1) == 0)
			if(min(cnt[0], cnt[1]) <= (n - k - 1) / 2) printf("Daenerys\n");
			else printf("Stannis\n");
		else if(cnt[1] <= (n - k - 1) / 2) printf("Daenerys\n");
		else printf("Stannis\n");
	}else{//Daenerys moves last
		if((k & 1) == 0) printf("Daenerys\n");
		else if(cnt[0] <= (n - k) / 2) printf("Stannis\n");
		else printf("Daenerys\n");
	}
	return 0;
}