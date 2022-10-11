#include <iostream>
using namespace std;
int main()
{
	int n,i,x,a,ans=0;
	cin >> n;
	for (i=0;i<n;i++)
	{
		for(x=0;x<n;x++)
		{
			cin >> a;
			if (i==x)
			ans+=a;
			else if (i==n-x-1)
			ans+=a;
			else if (x==n-i-1)
			ans+=a;
			else if (i==(n-1)/2)
			ans+=a;
			else if (x==(n-1)/2)
			ans+=a;
		}
	}
	cout << ans;
}