#include <iostream>
//#include <fstream>
//#include <list>
//#include <stack>
//#include <deque>
//#include <utility>
//#include <queue>
//#include <set>
//#include <map>
//#include <bitset>
//#include <vector>
#include <cmath>
//#include <string>
#include <algorithm>
#include <iomanip>
//#include <ctime>
//#include <iterator>
#include <cstdio>
//#include <cstring>
//#include <cstdlib>


using namespace std;

//typedef long long ll;
//typedef long double ld;
//typedef unsigned long long ull;

//#define f first
//#define s second
////#define pb push_back
//#define mp make_pair

const int maxn = 2002;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int pa[maxn];
int pb[maxn];
int pab[maxn];
unsigned int dp[maxn][maxn];

int main()
{
//    srand( time( 0 ) );
//     freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, x, y;
    scanf ( "%d%d%d", &n, &x, &y );
    for ( int j = 0; j < n; j++ ) {
        double x;
        scanf ( "%lf", &x );
        pa[j] = 1000 * 1000 * ( x + eps );
    }
    for ( int j = 0; j < n; j++ ) {
        double x;
        scanf ( "%lf", &x );
        pb[j] = 1000 * 1000 * ( x + eps );
    }
    for ( int j = 0; j < n; j++ ) {
        int cnt1 = ( 1000 - pa[j] / 1000 ) * ( pb[j] / 1000 ) + pa[j];
        int cnt2 = ( 1000 - pb[j] / 1000 ) * ( pa[j] / 1000 ) + pb[j];
        pab[j] = max( cnt1, cnt2 );
    }
    dp[x][y] = 0;
    for ( int j = 0; j < n; j++ ) {
        int a = pa[j];
        int b = pb[j];
        int c = pab[j];
//        for ( int e = 1; e <= y; e++ )
//            dp[0][e - 1] = max( dp[0][e - 1], dp[0][e] + b );
//        for ( int i = 1; i <= x; i++ ) {
//            dp[i - 1][0] = max( dp[i - 1][0], dp[i][0] + a );
//            for ( int e = 1; e <= y; e++ ) {
//                if ( dp[i - 1][e] < dp[i][e] + a )
//                    dp[i - 1][e] = dp[i][e] + a;
//                if ( dp[i][e - 1] < dp[i][e] + b )
//                    dp[i][e - 1] = dp[i][e] + b;
//                if ( dp[i - 1][e - 1] < dp[i][e] + c )
//                    dp[i - 1][e - 1] = dp[i][e] + c;
//            }
//        }
        int X = min( x, j );
        int Y = min( y, j );
        for ( int i = X; i >= 0; i-- )
            for ( int e = Y; e >= 0; e-- ) {
                if ( dp[i + 1][e] < dp[i][e] + a )
                    dp[i + 1][e] = dp[i][e] + a;
                if ( dp[i][e + 1] < dp[i][e] + b )
                    dp[i][e + 1] = dp[i][e] + b;
                if ( dp[i + 1][e + 1] < dp[i][e] + c )
                    dp[i + 1][e + 1] = dp[i][e] + c;
            }
//        for ( int i = 0; i <= x; i++ )
//            for ( int e = 0; e <= y; e++ )
//                dp[0][i][e] = dp[1][i][e];
    }
    int ans = 0;
    for ( int i = 0; i <= x; i++ )
        for ( int e = 0; e <= y; e++ )
            ans = max( ans, (int)dp[i][e] );
    cout << fixed << setprecision( 20 ) << 1.0L * ans / 1000000;
    return 0;
}