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

const int maxn = 2e5 + 500;
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
    int n, j;
    scanf ( "%d", &n );
    for ( j = 0; j < n; j++ )
        scanf ( "%d", &a[j] );
    ll ans;
    int mi = inf + 100;
    for ( j = 0; j < n; j++ )
        mi = min( mi, a[j] );
    ans = 1LL * mi * n;
    int l, r;
    l = inf;
    r = -1;
    for ( j = 0; j < n; j++ ) {
        if ( a[j] == mi ) {
            l = min( l, j );
            r = max( r, j );
        }
    }
    int delta = n - ( r - l + 1 );
    l = r = inf;
    for ( j = 0; j < n; j++ )
        if ( a[j] == mi ) {
            if ( r == inf ) r = j;
            l = r;
            r = j;
            delta = max( delta, r - l - 1 );
        }
    ans += 1LL * delta;
    printf ( "%I64d", ans );
    return 0;
}