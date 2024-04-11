#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long a,b,c,d;
		cin >> a >> b >> c >> d;
		long long st=0,en=(1LL<<30);
		while (st!=en)
		{
			int mid=(st+en)/2;
			if (mid*c-a<=mid*d-b && mid*c>=a && mid*d>=b)
			en=mid;
			else
			st=mid+1;
		}
		if (st==(1LL<<30))
		cout << -1 << endl;
		else
		cout << st*d-b << endl;
	}
}