#include <iostream>
using namespace std;
int main()
{
	int n,i,m,ans=1;
	cin >> n;
	for (i=0;i<n-1;i++)
	{
		ans+=i+1;
		m=ans/n;
		if (n!=ans)
		ans-=n*m;
		cout << ans << " ";
	}
}