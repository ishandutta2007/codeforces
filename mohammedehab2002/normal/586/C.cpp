#include <iostream>
using namespace std;
int main()
{
	long long n,i,x,ans=0;
	cin >> n;
	long long v[n],d[n],p[n];
	for (i=0;i<n;i++)
	cin >> v[i] >> d[i] >> p[i];
	for (i=0;i<n;i++)
	{
		if (p[i]>=0)
		{
			long long e=0;
			for (x=i+1;x<n;x++)
			{
				if (p[x]>=0)
				{
					p[x]-=v[i]+e;
					if (p[x]<0)
					e+=d[x];
					if (v[i])
					v[i]--;
				}
			}
			ans++;
		}
	}
	cout << ans << endl;
	for (i=0;i<n;i++)
	{
		if (p[i]>=0)
		cout << i+1 << ' ';
	}
}