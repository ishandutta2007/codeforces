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

int n, m, a[ 1111 ][ 1111 ];
long long f[ 4 ][ 1111 ][ 1111 ];

int main (int argc, const char * argv[])
{
	scanf("%d%d", &n, &m);
	for ( int i = 1; i <= n; i++ )
		for ( int j = 1; j <= m; j++ ) scanf("%d", &a[i][j]);
	//---------------------------
	for ( int k = 0; k < 4; k++ )
		for ( int i = 0; i < 1111; i++ )
			for ( int j = 0; j < 1111; j++ )
				f[k][i][j] = -inf;
	//---------------------------
	f[0][1][1] = a[1][1];
	for ( int i = 1; i <= n; i++ )
		for ( int j = 1; j <= m; j++ )
		{
			if ( f[0][i][j] != -inf ) continue;
			f[0][i][j] = max( f[0][i - 1][j], f[0][i][j - 1] ) + a[i][j];
		}
	//---------------------------
	f[1][n][1] = a[n][1];
	for ( int i = n; i >= 1; i-- )
		for ( int j = 1; j <= m; j++ )
		{
			if ( f[1][i][j] != -inf ) continue;
			f[1][i][j] = max( f[1][i + 1][j], f[1][i][j - 1] ) + a[i][j];
		}
	//---------------------------
	f[2][1][m] = a[1][m];
	for ( int i = 1; i <= n; i++ )
		for ( int j = m; j >= 1; j-- )
		{
			if ( f[2][i][j] != -inf ) continue;
			f[2][i][j] = max( f[2][i - 1][j], f[2][i][j + 1] ) + a[i][j];
		}
	//---------------------------
	f[3][n][m] = a[n][m];
	for ( int i = n; i >= 1; i-- )
		for ( int j = m; j >= 1; j-- )
		{
			if ( f[3][i][j] != -inf ) continue;
			f[3][i][j] = max( f[3][i + 1][j], f[3][i][j + 1] ) + a[i][j];
		}
	long long result = -inf;
	//---------------------------
	for ( int i = 1; i <= n; i++ )
		for ( int j = 1; j <= m; j++ )
		{
			long long cur1 = f[0][i][j - 1] + f[1][i + 1][j] + f[2][i - 1][j] + f[3][i][j + 1];
			long long cur2 = f[0][i - 1][j] + f[1][i][j - 1] + f[2][i][j + 1] + f[3][i + 1][j];
			//cout << i << " " << j << " " << cur1 << "\n";
			result = max( result, cur1 );
			result = max( result, cur2 );
		}
	cout << result << "\n";
    return 0;
}