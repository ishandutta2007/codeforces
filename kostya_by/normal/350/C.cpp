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

int n, x[ 100100 ], y[ 100100 ], p[ 100100 ];
vector< char > ans;
vector< int > k;
vector< char > dir; 

void process( int x, int y )
{
	if ( y < 0 ) 
	{
		ans.pb( '1' ); k.pb( -y ); dir.pb( 'D' );
	}
	if ( y > 0 )
	{
		ans.pb( '1' ); k.pb( y ); dir.pb( 'U' );
	}
	if ( x < 0 ) 
	{
		ans.pb( '1' ); k.pb( -x ); dir.pb( 'L' );
	}
	if ( x > 0 )
	{
		ans.pb( '1' ); k.pb( x ); dir.pb( 'R' );
	}
}

int fun( int a )
{
	return max( x[a], -x[a] ) + max( y[a], -y[a] );
}

bool cmp( int a, int b )
{
	return fun( a ) < fun( b );
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for ( int i = 0; i < n; i++ ) scanf("%d%d", &x[i], &y[i]), p[i] = i;
    sort( p, p + n, cmp );
    for ( int i = 0; i < n; i++ )
    {
    	process( x[ p[i] ], y[ p[i] ] );
    	ans.pb( '2' ); k.pb( -1 ); dir.pb( '-' );
    	process( -x[ p[i] ], -y[ p[i] ] );
    	ans.pb( '3' ); k.pb( -1 ); dir.pb( '-' );
    } 
    cout << ans.size() << endl;
    for ( int i = 0; i < ans.size(); i++ )
    {
    	printf("%c", ans[i]);
    	if ( ans[i] != '1' ) 
    	{
    		printf("\n");
    		continue;
    	}
    	printf(" %d %c\n", k[i], dir[i]);
    }
    return 0;
}