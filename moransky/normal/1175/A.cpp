#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
int main(){
	int T; scanf("%d", &T);
	while(T--){
		LL n, k, ans = 0;
		scanf("%lld%lld", &n, &k);
		while(n){
			if(n % k) ans += n % k, n -= n % k;
			if(n)n /= k, ans++; 
		}
		printf("%lld\n", ans);
	}
	return 0;
}