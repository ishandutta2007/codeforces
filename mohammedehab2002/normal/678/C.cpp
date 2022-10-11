#include <iostream>
#include <algorithm>
using namespace std;
long long lcm(long long a,long long b)
{
	long long gcd=__gcd(a,b);
	return (a/gcd)*(b/gcd)*gcd;
}
int main()
{
	long long n,a,b,c,d;
	cin >> n >> a >> b >> c >> d;
	cout << (n/a)*c+(n/b)*d-(n/lcm(a,b))*min(c,d);
}