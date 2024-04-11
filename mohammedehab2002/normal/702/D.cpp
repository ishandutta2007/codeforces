#include <iostream>
using namespace std;
long long d,k,a,b,t;
long long go(long long car)
{
	car=min(car,d);
	return car*a+(d-car)*b+(car-1)/k*t;
}
int main()
{
	cin >> d >> k >> a >> b >> t;
	cout << min(go(k),min(go(d),go((d/k)*k)));
}