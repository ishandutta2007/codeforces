#include <iostream>
using namespace std;
int main()
{
	long long n,sum,ans=0;
	cin >> n >> sum;
	for (int i=0;i<n;i++)
	{
		char x;
		int d;
		cin >> x >> d;
		if (x=='+')
		sum+=d;
		else
		{
			if (sum>=d)
			sum-=d;
			else
			ans++;
		}
	}
	cout << sum << ' ' << ans;
}