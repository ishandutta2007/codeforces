#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , f[1010] , s[1010] , cnt[1010] , c;

int main()
{
	int i , j;
	cin >> n;
	for (i = 2 ; i <= n ; i++)
	{
		cin >> j;
		f[i] = j;
		s[j]++; 
	}
	for (i = 1 ; i <= n ; i++)
	{
		if (s[i] == 0) 
		{
			cnt[i] = -1;
			cnt[f[i]]++;
		}
	}
	for (i = 1 ; i <= n ; i++)
	{
		if (cnt[i] >= 0 && cnt[i] <= 2)
		{
			c = 1;
			break;
		}
	}
	if (c) cout << "No\n";
	else cout << "Yes\n";
	return 0;
}