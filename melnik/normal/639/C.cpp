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
int suff[maxn];

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n, k;
    scanf ( "%d%d", &n, &k );
    for ( int j = 0; j <= n; j++ )
        scanf ( "%d", &a[j] );
    suff[n + 1] = 0;
    for ( int j = n; j >= 0; j-- ) {
        ll cur = 2LL * suff[j + 1] + 1LL * a[j];
        if ( abs( cur ) >= 1LL * inf )
            suff[j] = inf;
        else
            suff[j] = cur;
    }
    int ans = 0;
    int cur = 0;
    for ( int j = 0; j <= n; j++ ) {
        if ( suff[j + 1] == inf ) {
            if ( abs( cur ) % 2 )
                break;
            cur = cur / 2 + a[j];
            continue;
        }
        int stR = suff[j + 1];
        ll st = -1LL * cur - 4LL * stR;
        if ( abs( st ) % ( 2LL ) == 1LL ) {
            if ( abs( cur ) % 2 )
                break;
            cur = cur / 2 + a[j];
            continue;
        }
        ll newSt = st / ( 2LL );
        if ( abs( newSt ) <= 1LL * k )
            ++ans;
        if ( ( newSt == 0LL && j == n ) || newSt == a[j] )
            --ans;
        if ( abs( cur ) % 2 )
            break;
        cur = cur / 2 + a[j];
//        printf ( "%d ", newSt );
    }
    printf( "%d\n", ans );
    return 0;
}