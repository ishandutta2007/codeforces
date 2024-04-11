#include <iostream>
using namespace std;
int main()
{
	int n,a,b,ans=0;
	cin >> n >> a >> b;
	while (n>=0)
	{
		if (n%b==0)
		{
			cout << "YES\n" << ans << ' ' << n/b;
			return 0;
		}
		n-=a;
		ans++;
	}
	cout << "NO";
}