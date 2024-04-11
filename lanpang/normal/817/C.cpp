#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

long long n , s , l , r , m;

long long mmp(long long x)
{
	long long f , p=0;
	f = x;
	while (f > 0)
	{
		p += f%10;
		f/=10;
	}
	return x-p;
}

int main ()
{
	int i;
	cin >> n >> s;
	if (mmp(n) < s)
	{
		cout << "0\n";
	}
	else
	{
		l = 1;
		r = n;
		while (1)
		{
			m = (l+r)/2;
			if (mmp(m) >= s && mmp(m-1) < s)
			{
				break;
			}
			if (mmp(m) >= s)
			{
				r = m;
			}
			else
			{
				l = m+1;
			}
		}
		cout << n-m+1 << "\n";
	}
	//system("PAUSE");
	return 0;
}