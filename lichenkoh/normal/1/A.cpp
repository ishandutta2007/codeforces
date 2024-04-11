#include <iostream>
#include <assert.h>
using namespace std;
int main()
{
	unsigned long long n,m,a;
	cin >> n;
	cin >> m;
	cin >> a;
	unsigned long long x = n/a;
	if (n%a != 0) x++;
	unsigned long long y = m/a;
	if (m%a != 0) y++;
	cout<<(x*y)<<endl;
	return 0;
}