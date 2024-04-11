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

LL x , y , i , c;

int main()
{
	cin >> x >> y;
	for (i = 2 ; i <= y ; i++)
	{
		if (x%i != i-1)
		{
			c = 1;
			break;
		}
	}
	if (c) cout << "No\n";
	else cout << "Yes\n";
	return 0;
}