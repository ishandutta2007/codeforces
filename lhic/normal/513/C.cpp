#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;


int n;
int l[10];
int r[10];

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> l[i] >> r[i];

	ld ans = 0;
	for (int i = 1; i <= 10000; ++i)
	{
		for (int a = 0; a < n; ++a)
		{
			if (r[a] < i)
				continue;
			for (int m = 1; m < 1 << n; ++m)
			{
				if (m == 1 << a)
					continue;
				int fl = 0;
				for (int j = 0; j < n; ++j)
				{
					if (m & (1 << j))
					{
						if (l[j] > i || r[j] < i)
						{
							fl = 1;
							break;
						}
					}
					else
					{
						if (j != a)
						{
							if (l[j] >= i)
							{
								fl = 1;
								break;
							}
						}
					}
				}
				if (fl)
					continue;

				ld v = 1;
				for (int j = 0; j < n; ++j)
				{
					if (m & (1 << j))
					{
						v /= (r[j] - l[j] + 1);
					}
					else
					{
						if (j != a)
						{
							v *= min((ld)1.0, (ld)(i - l[j]) / (r[j] - l[j] + 1));
						}
						else
						{
							v *= min((ld)1.0, (ld)(r[a] - i) / (r[a] - l[a] + 1));
						}
					}
				}
				if (m & (1 << a))
					v /= __builtin_popcount(m);
				ans += i * v;
			}
		}
		//cout << ans << " ";
	}

	cout.setf(ios::fixed);
	cout.precision(20);
	cout << ans;
	return 0;
}