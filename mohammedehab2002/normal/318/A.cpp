#include <iostream>
using namespace std;
int main()
{
	long long n,k,i=0,x,ans;
	cin >> n >> k;
	if (k*2-1<=n)
	cout << k*2-1;
	else
	{
		if (n%2)
		ans=(n+1)/2;
		else
		ans=n/2;
		cout << (k-ans)*2;
	}
}