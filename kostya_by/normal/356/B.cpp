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

long long gcd( long long a, long long b )
{
	if ( a != 0 ) return gcd( b % a, a ); else return b;
}

long long lcm( long long a, long long b )
{
	return ( a / gcd( a, b ) ) * b;
}

long long n, m, x, y, mul, ans = 0;
char a[ 1000100 ];
char b[ 1000100 ];
int f1[ 26 ][ 1000100 ], f2[ 26 ][ 1000100 ];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m; gets( a ); gets( a ); gets( b );
    x = strlen( a );
    y = strlen( b ); 
    int gg = gcd( x, y );
    long long ll = lcm( x, y );
    mul = ( n * x ) / ll;
    for ( int i = 0; i < x; i++ ) f1[ a[i] - 'a' ][i % gg]++;
    for ( int i = 0; i < y; i++ ) f2[ b[i] - 'a' ][i % gg]++;
    for ( int i = 0; i < 26; i++ )
    	for ( int j = 0; j < gg; j++ )
    	{
    		long long a = f1[i][j], b = f2[i][j];
    		ans += a * b;
    	}
    cout << n * x - ans * mul << endl;
    return 0;
}