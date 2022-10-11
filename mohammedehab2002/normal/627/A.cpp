#include <iostream>
using namespace std;
int main()
{
	long long x,y,ans=1;
	cin >> x >> y;
	x-=y;
	for (int i=0;i<50;i++)
	{
		if (y&(1LL<<i))
		ans*=2LL;
	}
	if (!x)
	ans-=2LL;
	for (int i=0;i<50;i++)
	{
		if (x&(1LL<<i))
		{
			if (!i)
			ans=0;
			else if (y&(1LL<<(i-1)))
			ans=0;
		}
	}
	cout << ans;
}