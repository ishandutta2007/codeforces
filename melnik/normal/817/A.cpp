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

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int x1, y1, x2, y2, x, y;
    scanf ( "%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x, &y );
    if ( abs( x1 - x2 ) % x ) {
        puts( "NO" );
        return 0;
    }
    if ( abs( y1 - y2 ) % y ) {
        puts( "NO" );
        return 0;
    }
    int c1 = abs( x1 - x2 ) / x;
    int c2 = abs( y1 - y2 ) / y;
    if ( ( c1 & 1 ) != ( c2 & 1 ) )
    	puts( "NO" );
    else
    	puts( "YES" );
    return 0;
}