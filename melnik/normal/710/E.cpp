#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
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

const int maxn = 40000500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

ll dp[maxn];

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, x, y;
    scanf ( "%d%d%d", &n, &x, &y );
    for ( int j = 0; j < maxn; j++ )
    	dp[j] = 1LL * inf * inf;
    dp[1] = 1LL * x;
    for ( int j = 2; j < maxn; j++ ) {
    	dp[j] = min( dp[j], dp[j - 1] + 1LL * x );
    	if ( j % 2 == 0 )
    		dp[j] = min( dp[j], dp[j / 2] + 1LL * y );
        int cur = j;
        while ( cur >= 2 && dp[cur - 1] > 1LL * x + dp[cur] ) {
            dp[cur - 1] = 1LL * x + dp[cur];
            --cur;
    	}
    }
    cout << dp[n];
    return 0;
}