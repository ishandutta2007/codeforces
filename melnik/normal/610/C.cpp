#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <ext\hash_set>
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

const int maxn = 1e5;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int k[1000][1000];

void init ( int x, int y ) {
    int j, i;
    for ( j = 0; j < x; j++ )
        for ( i = y; i < 2 * y; i++ )
            k[i][j] = k[i - y][j];
    for ( j = x; j < 2 * x; j++ )
        for ( i = 0; i < y; i++ )
            k[i][j] = 1 ^ ( k[i][2 * x - j - 1] );
    for ( j = x; j < 2 * x; j++ )
        for ( i = y; i < 2 * y; i++ )
            k[i][j] = k[i][2 * x - j - 1];
}

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int j, x, y, n, i;
    scanf ( "%d", &n );
    if ( n == 0 ) {
        printf ( "+\n" );
        return 0;
    }
    k[0][0] = 1;
    k[1][0] = 1;
    k[0][1] = 1;
    k[1][1] = 0;
    x = y = 2;
    for ( j = 2; j <= n; j++ ) {
        init( x, y );
        x *= 2;
        y *= 2;
    }
    for ( j = 0; j < x; j++ ){
        for ( i = 0; i < y; i++ )
            if ( k[j][i] ) printf ( "+" );
                else printf ( "*" );
        printf ( "\n" );
    }
    return 0;
}