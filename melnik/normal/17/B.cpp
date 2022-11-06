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

set < int > offers[maxn];
int q[maxn];

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d", &n );
    for ( int j = 1; j <= n; j++ )
        scanf ( "%d", &q[j] );
    int q;
    scanf ( "%d", &q );
    int cnt = n - 1;
    while ( q-- ) {
        int u, v, c;
        scanf ( "%d%d%d", &u, &v, &c );
        if ( offers[v].empty() )
            --cnt;
        offers[v].insert( c );
    }
    if ( cnt > 0 ) {
        puts( "-1" );
        return 0;
    }
    int ans = 0;
    int maxCost = 0;
    for ( int j = 1; j <= n; j++ )
        if ( !offers[j].empty() ) {
            ans += *offers[j].begin();
            maxCost = max( *offers[j].begin(), maxCost );
        }
    if ( !cnt )
        printf( "%d\n", ans );
    else
        printf( "%d\n", ans - maxCost );
    return 0;
}