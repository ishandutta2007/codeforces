#include <iostream>
#include <math.h>
using namespace std;
template <class t>
t abs(t x)
{
	return (x>0)? x:-x;
}
int main()
{
	long long x,y,m,ans=0;
	cin >> x >> y >> m;
	if (x<1 && y<1 && x<m && y<m)
	{
		cout << -1;
		return 0;
	}
	if (x>m || y>m)
	{
		cout << 0;
		return 0;
	}
	if (x<0 && y>0)
	{
		ans+=abs(ceil((double)(x/y)));
		x%=y;
	}
	else if (x>0 && y<0)
	{
		ans+=abs(ceil((double)(y/x)));
		y%=x;
	}
	while (x<m && y<m)
	{
		if (x>=m || y>=m)
		{
			cout << ans;
			break;
		}
		if (x>y)
		y+=x;
		else
		x+=y;
		ans++;
	}
	cout << ans;
}