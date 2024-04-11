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

int x , y;

int main()
{
	cin >> x >> y;
	if (y <= 1)
	{
		if (y == 0) cout << "No\n";
		else
		{
			if (x == 0) cout << "Yes\n";
			else cout << "No\n";
		}
	}
	else
	{
		if (x >= y-1 && x%2 != y%2) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}