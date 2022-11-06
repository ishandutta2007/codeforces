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

const int maxn = 205;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

char t[maxn];
int dp[maxn][maxn][maxn] = { 0 };

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d\n", &n );
    gets( t );
    int r, g, b, j, i, y;
    r = g = b = 0;
    for ( j = 0; j < n; j++ ) {
        if ( t[j] == 'R' ) r++;
        if ( t[j] == 'G' ) g++;
        if ( t[j] == 'B' ) b++;
    }
    dp[n][g][b] = 1;
    for ( int pos = n; pos > 1; pos-- )
        for ( i = n; i >= 0; i-- )
            for ( y = n; y >= 0; y-- ) {
                if ( dp[pos][i][y] ) {
                    j = pos - i - y;
//                    printf ( "%d %d %d\n", )
                    if ( i && y )
                        dp[pos - 1][i - 1][y - 1] = 1;
                    if ( j && y )
                        dp[pos - 1][i + 1][y - 1] = 1;
                    if ( i && j )
                        dp[pos - 1][i - 1][y + 1] = 1;
                    if ( i > 1 )
                        dp[pos - 1][i - 1][y] = 1;
                    if ( y > 1 )
                        dp[pos - 1][i][y - 1] = 1;
                    if ( j > 1 )
                        dp[pos - 1][i][y] = 1;
                }
            }
    if ( dp[1][0][1] )
        printf ( "B" );
    if ( dp[1][1][0] )
        printf ( "G" );
    if ( dp[1][0][0] )
        printf ( "R" );
    return 0;
}