#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n,m,i,x,ans=0;
	cin >> n >> m;
	for (i=0;i<n+m;i++)
	{
		for (x=0;x<n+m;x++)
		{
			if (pow(i,2)+x==n && pow(x,2)+i==m)
			ans++;
		}
	}
	cout << ans;
}