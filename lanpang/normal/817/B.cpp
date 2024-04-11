#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

long long n , a[100001] , ans , m , t;

long long ccc(long long x , long long y)
{
	long long p=1;
	for (int i = 1 ; i <= x ; i++)
	{
		p*=(y-i+1);
		p/=i;
	}
	return p;
}

int main ()
{
	int i;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%I64d",&a[i]);
	}
	sort(a+1,a+n+1);
	i = 4;
	while (a[i] == a[i-1] && i <= n)
	{
		i++;
	}
	i--;
	m = i;
	for (i = 1 ; i <= m ; i++)
	{
		if (a[i] == a[3])
		{
			t++;
		}
	}
	if (m == 3)
	{
		ans = 1;
	}
	else
	{
		ans = ccc(3-(m-t),t);
	}
	cout << ans << "\n";
	//system("PAUSE");
	return 0;
}