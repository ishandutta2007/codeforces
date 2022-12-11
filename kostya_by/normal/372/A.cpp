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
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, a[ 500500 ];

bool check( int x )
{
    for ( int i = 1; i <= x; i++ )
    {
        if ( 2 * a[i] > a[n - x + i] ) return false;
    }
    return true;
}

int main (int argc, const char * argv[])
{
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ ) scanf("%d", &a[i]);
    sort( a + 1, a + n + 1 );
    int l = 1, r = n / 2, res = 0;
    while ( l <= r )
    {
        int x = (l + r) / 2;
        if ( check( x ) )
        {
            res = max( res, x );
            l = x + 1;
        } else r = x - 1;
    }
    printf("%d\n", n - res);
    return 0;
}