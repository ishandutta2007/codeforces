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

int n , ans , i;

int main()
{
	cin >> n;
	for (i = 1 ; i <= n/2 ; i++)
	{
		if ((n-i)%i == 0) ans++; 
	}
	cout << ans << "\n";
	return 0;
}