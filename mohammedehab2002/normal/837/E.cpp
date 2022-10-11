#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	long long a,b,ans=0;
	cin >> a >> b;
	while (b)
	{
		long long g=__gcd(a,b),tmp=b/g,mx=0;
		a/=g;
		for (long long i=1;i*i<=a;i++)
		{
			if (a%i==0)
			{
				if (i>1)
				mx=max(mx,(tmp/i)*i);
				if (i*i!=a)
				mx=max(mx,(tmp/(a/i))*(a/i));
			}
		}
		ans+=tmp-mx;
		b=mx*g;
		a*=g;
	}
	cout << ans;
}