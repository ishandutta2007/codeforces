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

int n, k, a[ 222 ], answer = -1000000000, b[ 222 ], c[ 222 ], m, x;

int main (int argc, const char * argv[])
{
	cin >> n >> k;
	for ( int i = 0; i < n; i++ ) cin >> a[i];
	for ( int l = 0; l < n; l++ )
		for ( int r = l; r < n; r++ )
		{
			m = 0;
			x = 0;
			int sum = 0;
			for ( int i = 0; i < l; i++ ) b[ m++ ] = a[i];
			for ( int i = l; i <= r; i++ ) c[ x++ ] = a[i], sum += a[i];
			for ( int i = r + 1; i < n; i++ ) b[ m++ ] = a[i];
			sort( b, b + m, greater< int >() );
			sort( c, c + x );
			for ( int i = 0; i < k; i++ )
			{
				if ( i >= x ) break;
				if ( i >= m ) break;
				if ( c[i] > b[i] ) break;
				sum -= c[i];
				sum += b[i];
			}
			answer = max( answer, sum );
		}
	cout << answer << "\n";
    return 0;
}