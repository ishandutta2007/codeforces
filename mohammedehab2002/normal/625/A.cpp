#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	long long n,a,b,c;
	cin >> n >> a >> b >> c;
	if (b-c>=a)
	{
		cout << (long long)(n/a);
		return 0;
	}
	long long g=max((n-c)/(b-c),0LL),gp=g*(b-c),p=(n-gp)/a;
	cout << g+p;
}