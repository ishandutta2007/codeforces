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

int k, x, n, m, f[ 55 ];
char fi[ 55 ], se[ 55 ];

void process( char a, char b, char c, char d, int ac1, int ac2 )
{
    if ( n == 1 && a != b ) return;
    if ( m == 1 && c != d ) return;
    if ( ac1 * 2 > n ) return;
    if ( ac2 * 2 > m ) return;  
    f[1] = ac1; fi[1] = a; se[1] = b;
    f[2] = ac2; fi[2] = c; se[2] = d;
    for ( int i = 3; i <= k; i++ ) 
    {
        f[i] = f[i - 2] + f[i - 1] + ( se[i - 2] == 'A' && fi[i - 1] == 'C' ? 1 : 0 );
        fi[i] = fi[i - 2];
        se[i] = se[i - 1];
        if ( f[i] > x ) return;
    }
    if ( f[k] != x ) return;
    //-------------------------------
    string s1 = ""; for ( int i = 0; i < ac1; i++ ) s1 += "AC";
    if ( s1[0] != a ) s1 = a + s1;
    while ( s1.size() + 1 < n ) s1 += 'B';
    if ( s1.size() + 1 == n ) s1 += b;
    if ( s1.size() != n ) return;
    if ( s1[n - 1] != b ) return;
    //-------------------------------
    string s2 = ""; for ( int i = 0; i < ac2; i++ ) s2 += "AC";
    if ( s2[0] != c ) s2 = c + s2;
    while ( s2.size() + 1 < m ) s2 += 'B';
    if ( s2.size() + 1 == m ) s2 += d;
    if ( s2.size() != m ) return;
    if ( s2[m - 1] != d ) return;
    cout << s1 << "\n" << s2 << "\n";
    exit( 0 );
}

int main (int argc, const char * argv[])
{
    cin >> k >> x >> n >> m;
    for ( char c1 = 'A'; c1 <= 'C'; c1++ )
        for ( char c2 = 'A'; c2 <= 'C'; c2++ )
            for ( char c3 = 'A'; c3 <= 'C'; c3++ )
                for ( char c4 = 'A'; c4 <= 'C'; c4++ )
                    for ( int ac1 = 0; ac1 <= n; ac1++ )
                        for ( int ac2 = 0; ac2 <= m; ac2++ )
                            process( c1, c2, c3, c4, ac1, ac2 );
    cout << "Happy new year!\n";
    return 0;
}