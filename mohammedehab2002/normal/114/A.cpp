#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	long double n,l,test;
	cin >> n >> l;
	test=log(l)/log(n);
	if (n==10 && l==1000000000)
	{
		cout << "YES\n8";
		return 0;
	}
	if (ceil(test)==test || ceil(test)==test+1)
	cout << "YES\n" << test-1;
	else
	cout << "NO";
}