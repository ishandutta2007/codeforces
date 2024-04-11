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

const int maxn = 200500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn];

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n, x, y;
    scanf ( "%d%d%d", &n, &x, &y );
    for ( int j = 0; j < n; j++ )
        scanf ( "%d", &a[j] );
    sort( a, a + n );
    int j = 0;
    int ans = 0;
    while ( j < n && 2LL * x + 1LL * y >= 1LL * a[j] ) {
        int cnt = min( x, a[j] / 2 );
        a[j] -= 2 * cnt;
        x -= cnt;
        if ( y >= a[j] )
            y -= a[j];
        else
            x -= ( a[j] + 1 ) / 2;
        ++j;
        ++ans;
    }
    printf ( "%d", ans );
    return 0;
}