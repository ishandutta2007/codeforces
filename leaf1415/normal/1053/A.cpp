#include <iostream>
#define llint long long

using namespace std;

llint gcd(llint a, llint b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

llint n, m, k;

int main(void)
{
	cin >> n >> m >> k;
	
	llint d = gcd(n*m, k);
	llint bunbo = k/d;
	if(bunbo > 2){
		cout << "NO" << endl;
		return 0;
	}
	
	llint dn = gcd(n, d);
	llint N = n / dn;
	llint M = m / (d/dn);
	if(bunbo == 1){
		if(N == n) M *= 2;
		else N *= 2;
	}
	
	cout << "YES" << endl;
	cout << 0 << " " << 0 << endl;
	cout << N << " " << 0 << endl;
	cout << 0 << " " << M << endl;
	
	return 0;
}