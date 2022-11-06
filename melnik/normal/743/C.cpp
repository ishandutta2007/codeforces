#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cstdlib>


using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 100500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

bool solution( int n ) {
	for ( int j = 1; j <= ( 3 * n ) / 2; j++ ) {
		if ( j == n )
			continue;
		int x = j;
		if ( x - n <= 0 || ( x * n ) % ( x - n ) )
			continue;
		if ( ( n * x ) / ( x - n ) == n || ( n * x ) / ( x - n ) == x )
			continue;
		printf ( "%d %d %d\n", x, n, ( n * x ) / ( x - n ) );
		return true;
	}
	puts( "-1" );
	return false;
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d", &n );
    solution( n );
    // for ( int j = 1; j <= 10000; j++ ) {
    //     if ( !solution( j ) )
    //         printf ( "%d\n", j );
    //     if ( j % 100 == 0 )
    //         printf ( "kek%d\n", j );
    // }
    return 0;
}