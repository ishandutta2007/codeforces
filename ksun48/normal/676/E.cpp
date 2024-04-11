#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char s;
char stuff[10];
LL num[110000];
int q[110000];
int nq = 0;
int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i <= n; i++){
		scanf("%s", stuff);
		if(stuff[0] == '?'){
			q[i] = 1;
			nq++;
			num[i] = -1;
		} else {
			q[i] = 0;
			int neg = 0;
			if(stuff[0] == '-') neg = 1;
			int v = strlen(stuff);
			int c = 0;
			for(int j = neg; j < v; j++){
				c *= 10;
				c += stuff[j]-'0';
			}
			c *= (1-2*neg);
			num[i] = (LL)c;
		}
	}
	if(k == 0){
		int r = n+1-nq;
		if(num[0] == 0){
			printf("Yes\n");
			return 0;
		} else if(q[0] == 0){
			printf("No\n");
			return 0;			
		}
		if(r % 2 == 0){
			printf("No\n");	
		} else {
			printf("Yes\n");
		}
		return 0;
	}
	LL k2 = k;
	if(nq == 0){
		LL ans = 0;
		for(int i = n; i >= 0; i--){
			ans *= k2;
			ans += num[i];
			if(abs(ans) > 100000000000){
				ans = 1;
				break;
			}
		}
		if(ans == 0){	
			printf("Yes\n");				
		} else {
			printf("No\n");
		}
		return 0;
	}
	if(n % 2 == 0){
		printf("No\n");
		return 0;
	} else {
		printf("Yes\n");
	}
}