#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 150005;
int n;
LL ans = 0;
LL gcd(LL a, LL b) {
	return b ? gcd(b, a % b) : a;
} 
int main(){
	LL a, b;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld", &a, &b);
		ans = gcd(ans, (LL)a * b / gcd(a, b));
	} 
	LL t = -1;
	for (int i = 2; i * i <= min(ans, (LL)2e9); i++){
		if(ans % i == 0) {
			if(t == -1)t = i;
			while(ans % i == 0) ans /= i;
		}
	}
	if(ans > 1 && t == -1) t = ans;
	if(gcd(a, t) > 1) t = gcd(a, t);
	else t = gcd(b, t); 
	printf("%lld\n", t);
	return 0;
}