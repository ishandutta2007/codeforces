#include <iostream>
using namespace std;
int main()
{
	long long a,b,ans=1;
	cin >> a >> b;
	for (long long i=a+1;i<=b;i++)
	{
		ans=(ans*i)%10;
		if (!ans)
		break;
	}
	cout << ans;
}