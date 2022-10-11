#include <iostream>
using namespace std;
int main()
{
	int n,a,b,c,d,i,ans=0;
	cin >> n;
	for (i=0;i<n;i++)
	{
		cin >> a >> b >> c >> d;
		ans+=(c-a+1)*(d-b+1);
	}
	cout << ans;
}