#include <cstdio>
typedef long long int ll;

char buf[1505]; int cur;

ll gcd(ll a, ll b){return b ? gcd(b, a % b) : a;}
void solve(ll a, ll b, bool flag){
	if(b != 1){
		if(a / b) printf("%I64d%c", a / b, flag ? 'A' : 'B');
		solve(b, a % b, !flag);
	}else if(a > 1) printf("%I64d%c", a - 1, flag ? 'A' : 'B');
}
int main(){
	ll a, b, g;
	scanf("%I64d%I64d", &a, &b);
	g = gcd(a, b);
	if(g != 1LL) printf("Impossible");
	else solve(a, b, true);
	printf("\n");
	return 0;
}