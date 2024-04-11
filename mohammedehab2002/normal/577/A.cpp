#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
	int n,m,i,ans=0;
	cin >> n >> m;
	for (i=1;i<=n;i++)
	{
		if (m%i==0 && m/i<=n)
		ans++;
	}
	cout << ans;
}