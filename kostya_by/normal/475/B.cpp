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

int n, m, id[ 22 ][ 22 ], h = 0;
string a, b;
int d[ 22 * 22 ][ 22 * 22 ];

void solve()
{
    cin >> n >> m >> a >> b;
    for ( int i = 0; i < n; i++ )
        for ( int j = 0; j < m; j++ )
            id[i][j] = h++;
    memset( d, 0, sizeof( d ) );
    for ( int i = 0; i < h; i++ ) d[i][i] = 1;
    for ( int i = 0; i < n; i++ )
        for ( int j = 0; j < m; j++ )
        {
            int ii, jj;
            if ( a[i] == '>' )
            {
                ii = i;
                jj = j + 1;
                if ( jj < m ) d[ id[i][j] ][ id[ii][jj] ] = 1;
            }
            if ( a[i] == '<' )
            {
                ii = i;
                jj = j - 1;
                if ( jj >= 0 ) d[ id[i][j] ][ id[ii][jj] ] = 1;
            }
            if ( b[j] == 'v' )
            {
                ii = i + 1;
                jj = j;
                if ( ii < n ) d[ id[i][j] ][ id[ii][jj] ] = 1;
            }
            if ( b[j] == '^' )
            {
                ii = i - 1;
                jj = j;
                if ( ii >= 0 ) d[ id[i][j] ][ id[ii][jj] ] = 1;
            }
        }
    for ( int k = 0; k < h; k++ )
        for ( int i = 0; i < h; i++ )
            for ( int j = 0; j < h; j++ )
                d[i][j] = max( d[i][j], d[i][k] * d[k][j] );
    /*for ( int i = 0; i < h; i++ )
    {
        for ( int j = 0; j < h; j++ ) cout << d[i][j] << " ";
        cout << "\n";
    }*/
    for ( int i = 0; i < h; i++ )
        for ( int j = 0; j < h; j++ )
            if ( !d[i][j] )
            {
                cout << "NO\n";
                return;
            }
    cout << "YES\n";
}

int main (int argc, const char * argv[])
{
    time_t start = clock();
    int t = 1;
    for ( int i = 0; i < t; i++ ) solve();
    cerr << fixed << setprecision( 6 ) << "Time: " << 1.0 * ( clock() - start ) / CLOCKS_PER_SEC << "\n";
    return 0;
}