#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	long long a,b,n1,n2,ans=0;
	cin >> a >> b;
	while (a>0 && b>0)
	{
		n1=max(a,b);
		n2=min(a,b);
		ans+=n1/n2;
		if (a>=b)
		a=n1%n2;
		else
		b=n1%n2;
	}
	cout << ans;
}