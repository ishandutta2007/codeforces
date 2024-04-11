#include <iostream>
using namespace std;
int main()
{
	int n,p,b,i,ans=0;
	cin >> n >> p >> b;
	int arr[n];
	for (i=0;i<n;i++)
	cin >> arr[i];
	for (i=0;i<n;i++)
	{
		if (arr[i]==1)
		{
			if (p==0)
			ans++;
			else
			p--;
		}
		else
		{
			if (b>0)
			b--;
			else
			{
				if (p==0)
				ans++;
				else
				p--;
			}
		}
	}
	cout << ans;
}