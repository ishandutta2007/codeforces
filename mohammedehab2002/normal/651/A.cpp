#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a,b,ans=0;
	cin >> a >> b;
	while (a && b && !(a==1 && b==1))
	{
		if (a<=b)
		{
			a++;
			b-=2;
		}
		else
		{
			a-=2;
			b++;
		}
		ans++;
	}
	cout << ans;
}