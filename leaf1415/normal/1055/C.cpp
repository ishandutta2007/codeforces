#include <iostream>
#include <stdlib.h>
#define llint long long

using namespace std;

llint la, ra, ta;
llint lb, rb, tb;
llint d;

llint gcd(llint a, llint b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

llint moddif(llint a, llint b){
	return (a - b + d) % d;
}

int main(void)
{
	cin >> la >> ra >> ta;
	cin >> lb >> rb >> tb;
	
	if(ra - la > rb - lb){
		swap(la, lb);
		swap(ra, rb);
		swap(ta, tb);
	}
	
	d = gcd(ta, tb);
	llint La = ra - la + 1, Lb = rb - lb + 1;
	
	llint ans;
	ans = max(0LL, La - moddif(lb%d, la%d));
	ans = max(ans, min(Lb, La + (d - moddif(lb%d, la%d))) - (d - moddif(lb%d, la%d)));
	cout << ans << endl;
	
	return 0;
}