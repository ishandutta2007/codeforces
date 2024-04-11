#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	long long k,d;
	long double t;
	cin >> k >> d >> t;
	cout << setprecision(12) << fixed;
	if (k%d==0)
	{
		cout << t;
		return 0;
	}
	d=(k/d+1)*d;
	long double x=k+(long double)(d-k)/2;
	long long y=t/x;
	t-=(long double)y*x;
	if (t<=k)
	cout << y*d+t;
	else
	cout << y*d+k+(long double)(t-k)*2;
}