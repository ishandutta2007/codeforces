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

int n, m, w[ 100100 ];

long long check( long long x )
{
    if ( x == 1 ) return 1;
    if ( x == 2 ) return 2;
    if ( x % 2 == 1 ) return x * (x - 1) / 2 + 1;
    return check( x - 1 ) + 1 + 3 * ( x - 2 ) / 2;
}

int main (int argc, const char * argv[])
{
    //for ( int i = 1; i <= 10; i++ ) cout << i << " " << check(i) << endl;
    scanf("%d%d", &n, &m);
    for ( int i = 0; i < m; i++ )
    {
        int q; scanf("%d%d", &q, &w[i]);
    }
    sort( w, w + m, greater< int >() );
    long long ans = 0;
    for ( int i = 0; i < m; i++ )
    {
        if ( check( i + 1 ) > n ) break;
        ans += w[i];
    }
    cout << ans << "\n";
    return 0;
}