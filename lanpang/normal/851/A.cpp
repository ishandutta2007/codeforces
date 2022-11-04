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

int main ()
{
	int i , n , k;
	cin >> n >> k >> i;
	if (i <= k) cout << i << "\n";
	else
	{
		if (i > n) cout << n+k-i << "\n";
		else cout << k << "\n";
	}
	//system("PAUSE");
	return 0;
}