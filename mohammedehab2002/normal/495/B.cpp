#include <iostream>
using namespace std;
int main()
{
	int n,k,i,d,ans=0;
	cin >> n >> k;
	d=n-k;
	if (d==0)
	cout << "infinity";
	else
	{
		for (i=1;i*i<=d;i++)
		{
			if (d%i==0)
			{
				if (i>k)
				ans++;
				if (i*i!=d && d/i>k)
				ans++;
			}
		}
		cout << ans;
	}
}