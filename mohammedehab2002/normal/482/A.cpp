#include <iostream>
using namespace std;
int main()
{
	int n,k,i,ans=1;
	cin >> n >> k;
	cout << "1 ";
	for (i=0;i<k;i++)
	{
		if (i%2)
		ans+=i-k;
		else
		ans+=k-i;
		cout << ans << " ";
	}
	for (i=k+2;i<=n;i++)
	cout << i << " ";
}