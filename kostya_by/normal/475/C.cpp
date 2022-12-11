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
#define right _right

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, m, ones, xs = -1, ys = -1, xf = -1, yf = -1;
bool right[ 1010 ][ 1010 ], down[ 1010 ][ 1010 ];
int f[ 1010 ][ 1010 ];
int answer = 1000000000;
char a[ 1010 ][ 1010 ];

int fsum( int x1, int y1, int x2, int y2 )
{
    return f[x2][y2] - f[x1 - 1][y2] - f[x2][y1 - 1] + f[x1 - 1][y1 - 1];
}

bool check( int x, int y )
{
    int x1 = xs, y1 = ys;
    int x2 = xs + x - 1, y2 = ys + y - 1;
    if ( x2 > xf || y2 > yf ) return false;
    if ( fsum( x1, y1, x2, y2 ) != ( x2 - x1 + 1 ) * ( y2 - y1 + 1 ) ) return false;
    while ( true )
    {
        if ( x2 == xf && y2 == yf ) return true;
        bool move_down = false;
        bool move_right = false;
        if ( x2 < xf && fsum( x2 + 1, y1, x2 + 1, y2 ) == y && right[x1][y2 + 1] ) move_down = true;
        if ( y2 < yf && fsum( x1, y2 + 1, x2, y2 + 1 ) == x &&  down[x2 + 1][y1] ) move_right = true;
        if ( move_right == true && move_down == true ) return false;
        if ( move_right == false && move_down == false ) return false;
        if ( move_right == true && move_down == false ) 
        {
            y1 += 1; y2 += 1;
        }
        if ( move_right == false && move_down == true )
        {
            x1 += 1; x2 += 1;
        }
    }
}

void solve()
{
    scanf("%d%d", &n, &m);
    for ( int i = 1; i <= n; i++ )
    {
        scanf("%s", a[i] + 1 );
        for ( int j = 1; j <= m; j++ ) if ( a[i][j] == 'X' && xs == -1 ) xs = i, ys = j; 
    }
    for ( int i = n; i >= 1; i-- )
        for ( int j = m; j >= 1; j-- )
            if ( a[i][j] == 'X' && xf == -1 ) xf = i, yf = j;
    //cout << xs << " " << ys << " " << xf << " " << yf << "\n";
    if ( xs > xf )
    {
        cout << -1 << "\n";
        return;
    }
    if ( ys > yf )
    {
        cout << -1 << "\n";
        return;
    }
    // -------------------------------
    for ( int i = 1; i <= n; i++ ) right[ i ][ m + 1 ] = true;
    for ( int j = m; j >= 1; j-- )
        for ( int i = 1; i <= n; i++ )
        {
            right[i][j] = right[i][j + 1];
            if ( a[i][j] == 'X' ) right[i][j] = false;
        }
    // -------------------------------
    for ( int j = 1; j <= m; j++ ) down[ n + 1 ][ j ] = true;
    for ( int i = n; i >= 1; i-- )
        for ( int j = 1; j <= m; j++ )
        {
            down[i][j] = down[i + 1][j];
            if ( a[i][j] == 'X' ) down[i][j] = false;
        } 
    // -------------------------------
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
            f[i][j] = ( a[i][j] == 'X' ) + f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
    ones = f[n][m];
    if ( fsum( xs, ys, xf, yf ) != ones ) 
    {
        cout << -1 << "\n";
        return;
    }
    for ( int x = 1; x <= n; x++ )
        for ( int y = 1; y <= m; y++ )
        {
            if ( x * y >= answer ) continue;
            if ( check( x, y ) ) answer = x * y;
        }
    if ( answer == 1000000000 ) answer = -1;
    cout << answer << "\n";
}

int main (int argc, const char * argv[])
{
    time_t start = clock();
    int t = 1;
    for ( int i = 0; i < t; i++ ) solve();
    cerr << fixed << setprecision( 6 ) << "Time: " << 1.0 * ( clock() - start ) / CLOCKS_PER_SEC << "\n";
    return 0;
}