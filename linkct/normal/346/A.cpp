#include <cstdio>

int gcd(int a, int b){return b ? gcd(b, a % b) : a;}
int main(){
	int i, cur = 0, t, maxv = 0, n;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &t);
		cur = gcd(cur, t);
		if(t > maxv) maxv = t;
	}
	printf("%s\n", (maxv / cur - n) & 1 ? "Alice" : "Bob");
	return 0;
}