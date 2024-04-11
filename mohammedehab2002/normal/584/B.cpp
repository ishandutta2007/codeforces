#include <iostream>
using namespace std;
#define mod 1000000007
int main()
{
	long long n,i,a=1,b=1;
	cin >> n;
	for (i=0;i<n*3;i++)
	a=(a*3)%mod;
	for (i=0;i<n;i++)
	b=(b*7)%mod;
	cout << (a-b+mod)%mod;
}