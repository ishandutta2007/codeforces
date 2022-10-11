#include <iostream>
using namespace std;
int main()
{
	long long n,mod=1000000007,f[3];
	cin >> f[0] >> f[1] >> n;
	f[2]=f[1]-f[0];
	int sign=((n-1)/3)%2;
	cout << (f[(n-1)%3]*(sign? -1:1)+2LL*mod)%mod;
}