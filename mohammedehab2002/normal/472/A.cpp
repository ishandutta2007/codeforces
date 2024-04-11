#include <iostream>
using namespace std;
int main()
{
	int n,i,x,test=0,ans=4;
	cin >> n;
	again: for (i=ans;i<n;i++)
	{
		for (x=2;x<i;x++)
		{
			if (i%x)
			test++;
		}
		if (test+2<i)
		break;
		else
		test=0;
	}
	test=0;
	ans=i;
	for (i=2;i<n-ans;i++)
	{
		if ((n-ans)%i)
		test++;
	}
	if (test+2<n-ans)
	cout << ans << " " << n-ans;
	else
	{
		ans++;
		test=0;
		goto again;
	}
}