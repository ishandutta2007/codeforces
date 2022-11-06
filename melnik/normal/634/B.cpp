#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
//#include <ext\hash_set>
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

const int maxn = 100500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

ll dp[64][2] = { 0LL };
int a[64] = { 0 }, b[64] = { 0 };

bool valid( int j, int c1, int c2, int fl ) {
    if ( ( c1 + c2 + fl ) % 2 == a[j] &&
        ( c1 ^ c2 ) == b[j] )
            return 1;
    return 0;
}

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio( false );
    ll s, x;
    cin >> s >> x;
    ll s1 = s, x1 = x;
    int pos = 0;
    while ( s ) {
        a[pos++] = s % 2LL;
        s /= 2LL;
    }
    int cur = pos;
    pos = 0;
    while ( x ) {
        b[pos++] = x % 2LL;
        x /= 2LL;
    }
    if ( valid( 0, 0, 0, 0 ) )
        dp[1][0] += 1LL;
    if ( valid( 0, 1, 0, 0 ) )
        dp[1][0] += 1LL;
    if ( valid( 0, 0, 1, 0 ) )
        dp[1][0] += 1LL;
    if ( valid( 0, 1, 1, 0 ) )
        dp[1][1] += 1LL;
    for ( int j = 1; j < 50; j++ )
        for ( int c1 = 0; c1 < 2; c1++ )
            for ( int c2 = 0; c2 < 2; c2++ )
                for ( int fl = 0; fl < 2; fl++ ) {
                    if ( valid( j, c1, c2, fl ) )
                        dp[j + 1][ ( c1 + c2 + fl ) / 2 ] += dp[j][fl];
                }
    ll ans = dp[50][0];
    if ( s1 == x1 )
        ans -= 2LL;
    cout << ans;
    return 0;
}