#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <bitset>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const int inf = 1e9;

using namespace std;

int n, k, pref[ 2000100 ], ans = 0;

int main (int argc, const char * argv[])
{
	scanf("%d%d", &n, &k);
	for ( int i = 1; i <= n; i++ )
	{
		int a; scanf("%d", &a);
		pref[a]++;
	}
	for ( int i = 1; i < 2000100; i++ ) pref[i] += pref[i - 1];
	for ( int cur = 1; cur < 2000100; cur++ )
	{
		int last = 0;
		bool fl = true;
		for ( int i = cur; i < 2000100; i += cur )
		{
			if ( last < i - 1 )
				if ( pref[i - 1] - pref[ last ] > 0 ) fl = false;
			last = i + k;
		}
		if ( fl ) ans = cur;
	}
	cout << ans << "\n";
    return 0;
}