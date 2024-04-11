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
const int mod = 1000000007;

using namespace std;

int n, num[ 1048576 ], ptwo[ 1048576 ], bits[ 1048576 ];

void solve( int l, int r )
{
	if ( l == r ) return;
	int x = (l + r) / 2;
	solve( l, x );
	solve( x + 1, r );
	int len = x - l + 1;
	for ( int i = l; i <= x; i++ ) num[i] += num[i + len];
}

int main (int argc, const char * argv[])
{
	ptwo[ 0 ] = 1;
	for ( int i = 1; i < 1048576; i++ ) ptwo[i] = ( ptwo[i - 1] + ptwo[i - 1] ) % mod;
	scanf("%d", &n);
	for ( int i = 1; i <= n; i++ ) 
	{
		int x; scanf("%d", &x);
		num[ x ]++;
	}
	solve( 0, 1048575 );
	long long answer = 0;
	for ( int i = 0; i < 1048576; i++ )
	{
		long long value = ( ptwo[ num[ i ] ] + mod - 1 ) % mod;
		bits[ i ] = bits[ i / 2 ] ^ ( i % 2 );
		if ( bits[ i ] == 0 ) answer = ( answer + value ) % mod;
		if ( bits[ i ] == 1 ) answer = ( answer - value + mod ) % mod;
	}
	cout << answer << "\n";
    return 0;
}