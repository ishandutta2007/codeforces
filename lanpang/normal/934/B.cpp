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

int n , i , m;

int main()
{
	cin >> n;
	if (n <= 18)
	{
		for (i = 1 ; i <= n ; i++) cout << "6";
		cout << "\n";
	}
	else
	{
		if (n > 36) cout << "-1\n";
		else
		{
			m = n/2;
			for (i = 1 ; i <= m ; i++) cout << "8";
			if (n > m*2) cout << "0";
			cout << "\n";
		}
	}
	return 0;
}