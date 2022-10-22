#include <iostream>
#define llint long long

using namespace std;

llint n, k;
llint a, b;

llint gcd(llint a, llint b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

llint calcmx(llint x)
{
	(x+=2*k) %= k;
	llint ret = 1;
	for(llint i = x; i <= n*k; i+=k){
		if(i == 0) continue;
		ret = max(ret, n*k/gcd(n*k, i));
	}
	return ret;
}
llint calcmn(llint x)
{
	(x+=2*k) %= k;
	llint ret = n*k;
	for(llint i = x; i <= n*k; i+=k){
		if(i == 0) continue;
		ret = min(ret, n*k/gcd(n*k, i));
	}
	return ret;
}

int main(void)
{
	cin >> n >> k;
	cin >> a >> b;
	
	llint mn = k*n, mx = 1;
	mn = min(mn, calcmn(a+b)), mx = max(mx, calcmx(a+b));
	mn = min(mn, calcmn(a-b)), mx = max(mx, calcmx(a-b));
	mn = min(mn, calcmn(-a+b)), mx = max(mx, calcmx(-a+b));
	mn = min(mn, calcmn(-a-b)), mx = max(mx, calcmx(-a-b));
	
	cout << mn << " " << mx << endl;
	return 0;
}