#include <iostream>
using namespace std;
int main()
{
	int k,b,n,t;
	cin >> k >> b >> n >> t;
	n++;
	int i;
	long long init=1LL;
	for (i=1;i<n;i++)
	{
		init=init*k+b;
		if (init>t)
		break;
	}
	cout << n-i;
}