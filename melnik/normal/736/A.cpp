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

const int maxn = 100500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

ll dp[100];

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    int cur = 0;
    for ( int j = 1; j < 100; j++ ) {
        for ( int i = 0; i < 100; i++ )
            dp[i] = 0LL;
        dp[j] = 1LL;
        for ( int i = j; i > 1; i-- ) {
            dp[i - 1] += dp[i];
            dp[i - 2] += dp[i];
        }
        dp[0] += 2LL * dp[1];
        if ( dp[0] > n ) {
            cout << j - 1 << endl;
            return 0;
        }
    }
    return 0;
}