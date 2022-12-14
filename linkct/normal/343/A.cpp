#include <cstdio>
typedef long long int ll;

ll gcd(ll a, ll b){return b ? (gcd(b, a % b) + a / b) : 0;}
int main(){
	ll a, b;
	scanf("%I64d%I64d", &a, &b);
	printf("%I64d\n", gcd(a, b));
	return 0;
}