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
#include <cassert>
#include <stack>
#include <bitset>
#include <sstream>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, a[ 25 ], b[ 25 ], pref[ 25 ];
time_t start;

void rec( int pos )
{
	if ( 1.0 * ( clock() - start ) / CLOCKS_PER_SEC > 0.9 )
	{
		printf("NO");
		exit( 0 );
	}
	if ( pos == 0 )
	{
		bool fl = true;
		for ( int i = 1; i <= n; i++ ) if ( a[i] != b[i] + 1 ) fl = false;
		if ( fl )
		{
			printf("YES");
			exit( 0 );
		}
		return;
	}
	for ( int i = pos + 1; i <= n; i++ )
	{
		if ( pref[pos] + b[i] + 1 < a[i] ) return;
	}
	for ( int i = pos + 1; i <= n; i++ )
	{
		if ( a[pos] + 1 == a[i] ) continue;
		if ( a[pos] + b[i] + 1 <= a[i] )
		{
			b[i] += a[pos];
			rec( pos - 1 );
			b[i] -= a[pos];
		}
	}
}

int main (int argc, const char * argv[])
{
	start = clock();
	cin >> n;
	for ( int i = 1; i <= n; i++ ) cin >> a[i], pref[i] = pref[i - 1] + a[i];
	sort( a + 1, a + n + 1 );

	rec( n - 1 );

	printf("NO");

    return 0;
}