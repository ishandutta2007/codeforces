#include <cstdio>
const int ans[] = {0, 0, 1, 1, 2, 1, 2, 1};

bool isPrime(int x){
	for(int i = 2; i <= x / i; ++ i)
		if(x % i == 0) return false;
	return true;
}
int solve(){
	int n;
	scanf("%d", &n);
	if(n <= 7) return ans[n];
	if(n & 1) return isPrime(n) ? 1 : (isPrime(n - 2) ? 2 : 3);
	return 2;
}
int main(){
	printf("%d\n", solve());
	return 0;
}