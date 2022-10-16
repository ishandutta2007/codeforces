#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 300010;
int n, m;
LL x[N], p[N];
LL gcd(LL a, LL b){
	return b ? gcd(b, a % b) : a;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) 
		scanf("%lld", x + i);
	for(int i = 1; i <= m; i++)
		scanf("%lld", p + i);
		
	LL ans = x[2] - x[1];
	for(int i = 2; i < n; i++)
		ans = gcd(ans, x[i + 1] - x[i]);
	
	for(int i = 1; i <= m; i++){
		if(ans % p[i] == 0){
			printf("YES\n%lld %d\n", x[1], i);
			return 0;
		}
	}
	printf("NO");
	return 0;
}