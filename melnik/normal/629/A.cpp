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

const int maxn = 105;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

char t[maxn][maxn];

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n, j, i;
    scanf ( "%d\n", &n );
    for ( j = 0; j < n; j++ )
        gets( t[j] );
    ll ans = 0LL;
    for ( j = 0; j < n; j++ ) {
        int cnt = 0;
        for ( i = 0; i < n; i++ )
            if ( t[j][i] == 'C' )
                cnt++;
        ans += 1LL * ( cnt ) * ( cnt - 1 ) / 2LL;
    }
    for ( j = 0; j < n; j++ ) {
        int cnt = 0;
        for ( i = 0; i < n; i++ )
            if ( t[i][j] == 'C' )
                cnt++;
        ans += 1LL * ( cnt ) * ( cnt - 1 ) / 2LL;
    }
    cout << ans;
    return 0;
}