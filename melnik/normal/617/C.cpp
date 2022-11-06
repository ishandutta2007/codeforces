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

const int maxn = 2050;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

pair < int, int > a[maxn];
bool used[maxn];

ll dist ( int x1, int y1, int x2, int y2 ) {
    return 1LL * ( x1 - x2 ) * ( x1 - x2 ) + 1LL * ( y1 - y2 ) * ( y1 - y2 );
}

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n, x1, x2, y1, y2, i, j;
    ll ans = 9000000000000000000LL;
    scanf ( "%d", &n );
    scanf ( "%d%d%d%d", &x1, &y1, &x2, &y2 );
    for ( j = 0; j < n; j++ ) {
        scanf( "%d%d", &a[j].f, &a[j].s );
    }
    ll r1 = 0LL;
    for ( j = 0; j <= n; j++ ) {
        ll r2 = 0LL;
        for ( i = 0; i < n; i++ )
            if ( dist( a[i].f, a[i].s, x1, y1 ) <= r1 ) used[i] = 1;
                else used[i] = 0;
        for ( i = 0; i < n; i++ )
            if ( !used[i] )
                r2 = max( r2, dist( a[i].f, a[i].s, x2, y2 ) );
        ans = min( ans, r1 + r2 );
        if ( j != n )
            r1 = dist( a[j].f, a[j].s, x1, y1 );
    }
    cout << ans;
    return 0;
}