#include<cstdio>

int main() {
	int n;
	scanf("%d", &n);
	
	int x = 1, ans = 0;
	while(n>0) {
		ans++;
		n-=x;
		x*=2;
	}
	printf("%d\n", ans);
	
	return 0;
}