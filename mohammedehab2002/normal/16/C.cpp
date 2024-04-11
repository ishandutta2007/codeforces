#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a,b,c,d,e,f;
	cin >> a >> b >> c >> d;
	e=__gcd(c,d);
	c/=e;
	d/=e;
	f=min(a/c,b/d);
	cout << c*f << " " << d*f;
}