#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	long long l,r,x,y;
	cin >> l >> r >> x >> y;
	long long p=x*y,ans=0;
	for (long long a=x;a<=p;a+=x)
	{
		if (p%a==0)
		{
			long long b=p/a;
			if (b<a)
			break;
			if (__gcd(a,b)==x && l<=a && a<=r && l<=b && b<=r)
			ans+=1+(a!=b);
		}
	}
	cout << ans;
}