#include <iostream>
using namespace std;
int is_prime(int y)
{
	int j,m;
	for (j=2;j<=y;j++)
	{
		m=y%j;
		if (m==0 && y!=j)
		return 0;
	}
	return 1;
}
int main()
{
	int n,i,x,mod,test=0;
	long long ans=0;
	cin >> n;
	for (i=6;i<=n;i++)
	{
		for (x=3;x<i;x+=2)
		{
			mod=i%x;
			if (mod==0)
			{
				if (is_prime(x)==1)
				test++;
			}
		}
		mod=i%2;
		if (mod==0)
		test++;
		if (test==2)
		ans++;
		test=0;
	}
	cout << ans;
}