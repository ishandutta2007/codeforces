#include <iostream>
using namespace std;
int main()
{
	int a,b,ans=0,mod=0;
	cin >> a >> b;
	ans+=a;
	while (a!=0)
	{
		if (a%b && a>b)
		mod+=a%b;
		a/=b;
		ans+=a;
		if (a<b)
		{
			a+=mod;
			mod=0;
		}
	}
	cout << ans;
}