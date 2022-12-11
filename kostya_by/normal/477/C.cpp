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
#define next _next

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, m;
char s[ 2020 ], p[ 505 ];
int next[ 2020 ];
int f[ 2020 ][ 2020 ], answer[ 2020 ];

void solve()
{
    scanf("%s%s", s + 1, p + 1);
    n = strlen( s + 1 );
    m = strlen( p + 1 );
    for ( int i = 1; i <= n; i++ )
    {
        int pos = i;
        for ( int j = 1; j <= m; j++ )
        {
            while ( true )
            {
                if ( pos == n + 1 ) break;
                if ( s[ pos ] == p[ j ] ) break;
                pos += 1;
            }
            if ( pos == n + 1 )
            {
                pos = -1;
                break;
            }
            pos += 1;
        }
        if ( pos == -1 )
        {
            next[i] = -1;
            continue;
        } 
        next[i] = pos - 1;
    }
    //for ( int i = 1; i <= n; i++ ) cout << next[i] << " "; cout << "\n";
    for ( int i = 0; i < 2020; i++ )
        for ( int j = 0; j < 2020; j++ )
            f[i][j] = -1;
    f[0][0] = 0;
    for ( int i = 0; i < n; i++ )
        for ( int j = 0; j < n; j++ )
        {
            if ( f[i][j] == -1 ) continue;
            f[i + 1][j] = max( f[i + 1][j], f[i][j] );
            f[i + 1][j + 1] = max( f[i + 1][j + 1], f[i][j] ); 
            if ( next[i + 1] != -1 ) 
            {
                int rem = next[i + 1] - i - m;
                if ( j + rem <= n )
                    f[ next[ i + 1 ] ][ j + rem ] = max( f[ next[ i + 1 ] ][ j + rem ], f[i][j] + 1 );
            }
        }
    // for ( int i = 0; i <= n; i++ )
    // {
    //     for ( int j = 0; j <= n; j++ ) cout << f[i][j] << " ";
    //     cout << "\n";
    // }
    for ( int i = 0; i <= n; i++ ) cout << f[n][i] << " "; cout << "\n";
}

int main (int argc, const char * argv[])
{
    time_t start = clock();
    int t = 1;
    for ( int i = 0; i < t; i++ ) solve();
    cerr << fixed << setprecision( 6 ) << "Time: " << 1.0 * ( clock() - start ) / CLOCKS_PER_SEC << "\n";
    return 0;
}