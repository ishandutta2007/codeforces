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

char s[ 100100 ];
int n, x[ 100100 ], y[ 100100 ], z[ 100100 ];

bool check( int l, int r )
{
    if ( r - l + 1 <= 2 ) return true;
    int xx = x[r] - x[l - 1];
    int yy = y[r] - y[l - 1];
    int zz = z[r] - z[l - 1];
    if ( xx >= zz && zz >= yy && xx - yy <= 1 ) return true;
    if ( zz >= yy && yy >= xx && zz - xx <= 1 ) return true;
    if ( yy >= xx && xx >= zz && yy - zz <= 1 ) return true;
    return false;
}

int main (int argc, const char * argv[])
{
    gets( s ); n = strlen( s );
    for ( int i = 1; i <= n; i++ )
    {
        x[i] = x[i - 1] + ( s[i - 1] == 'x' );
        y[i] = y[i - 1] + ( s[i - 1] == 'y' );
        z[i] = z[i - 1] + ( s[i - 1] == 'z' );
    }
    int m; scanf("%d", &m);
    while ( m-- )
    {
        int l, r;
        scanf("%d%d", &l, &r);
        if ( check( l, r ) ) puts("YES"); else puts("NO");
    }
    return 0;
}