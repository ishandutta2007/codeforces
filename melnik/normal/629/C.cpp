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
const int base = 1e9 + 7;

int dp[maxn][maxn] = { 0 };
char t[100500];

int calc( int j, int i, int bal, int delta ) {
    if ( i + bal >= 0 && i + bal < maxn )
        return ( 1LL * dp[j][i] * dp[delta - j][i + bal] ) % base;
    return 0;
}

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n, m, j, i;
    scanf ( "%d%d\n", &n, &m );
    gets( t );
    dp[1][1] = 1;
    dp[0][0] = 1;
    for ( j = 1; j < maxn - 1; j++ ) {
        for ( i = 1; i < maxn - 1; i++ ) {
            dp[j + 1][i + 1] += dp[j][i];
            dp[j + 1][i + 1] %= base;
            dp[j + 1][i - 1] += dp[j][i];
            dp[j + 1][i - 1] %= base;
        }
        dp[j + 1][1] += dp[j][0];
        dp[j + 1][1] %= base;
    }
    int ans = 0;
    int bal = 0;
    int minBal = 0;
    for ( j = 0; j < m; j++ ) {
        if ( t[j] == '(' )
            ++bal;
        else
            minBal = min( minBal, --bal );
    }
    for ( j = 0; j <= n - m; j++ )
        for ( i = -minBal; i < maxn; i++ ) {
            if ( calc( j, i, bal, n - m ) )
                ans += calc( j, i, bal, n - m );
            ans %= base;
        }
    printf ( "%d", ans );
    return 0;
}