#include <iostream>
using namespace std;
int main()
{
	int n,mini=100010,ans=0,a,b,i;
	cin >> n;
	for (i=0;i<n;i++)
	{
		cin >> a >> b;
		mini=min(b,mini);
		ans+=mini*a;
	}
	cout << ans;
}