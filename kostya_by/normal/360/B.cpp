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
const long long inf = 1e18;

using namespace std;

int n, k;
long long a[ 2222 ];
int f[ 2222 ][ 2222 ]; 

bool check( long long x )
{
	//cout << x << ": \n";
	for ( int i = 1; i <= n; i++ )
		for ( int j = 1; j <= n; j++ )
			f[i][j] = k + 1;
	for ( int i = 1; i <= n; i++ ) f[i][i] = i - 1;
	long long diff, l, r;
	for ( int i = 1; i < n; i++ )
		for ( int j = 1; j <= i; j++ )
		{
			diff = i - j + 1;
			l = a[j] - x * diff;
			r = a[j] + x * diff;
			//cout << i << " " << j << " " << l << " " << r << " " << f[i][j] << endl;
			f[i + 1][j] = min( f[i + 1][j], f[i][j] + 1 );
			if ( l <= a[i + 1] && a[i + 1] <= r )
				f[i + 1][i + 1] = min( f[i + 1][i + 1], f[i][j] );  
		}
	//for ( int i = 1; i <= n; i++ ) cout << f[n][i] << " "; cout << endl;
	for ( int i = 1; i <= n; i++ ) if ( f[n][i] <= k ) return true;
	return false;
}

int main (int argc, const char * argv[])
{
    cin >> n >> k;
    for ( int i = 1; i <= n; i++ ) cin >> a[i];
    long long l = 0, r = 2000000000, res = 2000000000;
	while ( l <= r )
	{
		long long x = ( l + r ) / 2;
		if ( check( x ) )
		{
			res = min( res, x );
			r = x - 1;
		} else l = x + 1;
	}
	cout << res << "\n";
    return 0;
}