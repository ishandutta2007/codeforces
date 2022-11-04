#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , p , i;
char s[2010];

int main()
{
	cin >> n >> p >> s;
	for (i = 0 ; i < n ; i++)
	{
		if (s[i] == '.')
		{
			if (i >= p)
			{
				if (s[i-p] == '0') s[i] = '1';
				else s[i] = '0';
			}
			else
			{
				if (i < n-p)
				{
					if (s[i+p] == '.') s[i] = '0';
					else
					{
						if (s[i+p] == '0') s[i] = '1';
						else s[i] = '0';
					}
				}
				else s[i] = '0';
			}
		}
	}
	for (i = 0 ; i < n-p ; i++)
	{
		if (s[i] != s[i+p])
		{
			cout << s << "\n";
			return 0;
		}
	}
	cout << "No\n";
	return 0;
}