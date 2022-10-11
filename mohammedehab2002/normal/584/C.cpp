#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,t,i,d,x,y,k;
	string a,b;
	cin >> n >> t >> a >> b;
	string ans(n,0);
	d=n-t;
	for (i=0;i<n;i++)
	{
		if (d==0)
		break;
		if(a[i]==b[i])
		{
			ans[i]=a[i];
			d--;
		}
	}
	x=y=d;
	for (i=0;i<n;i++)
	{
		if (x==0 && y==0)
		break;
		if (ans[i]==0)
		{
			if (x)
			{
				ans[i]=a[i];
				x--;
				continue;
			}
			if (y)
			{
				ans[i]=b[i];
				y--;
			}
		}
	}
	for (i=0;i<n;i++)
	{
		if (ans[i]==0)
		{
			for (k='a';k<='z';k++)
			{
				if (a[i]!=k && b[i]!=k)
				{
					ans[i]=(char)k;
					break;
				}
			}
		}
	}
	if (y==0)
	cout << ans;
	else
	cout << -1;
}