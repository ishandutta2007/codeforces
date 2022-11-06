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

const int maxn = 1e5;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[400] = { 0 };
int b[400] = { 0 };

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n, j;
    scanf ( "%d\n", &n );
    char t;
    int x, y;
    for ( j = 0; j < n; j++ ) {
        scanf ( "%c %d %d", &t, &x, &y );
        if ( j != n - 1 )
            scanf ( "\n" );
        if ( t == 'M' ) {
            for ( ; x <= y; x++ )
                a[x]++;
        }
        if ( t == 'F' ) {
            for ( ; x <= y; x++ )
                b[x]++;
        }
    }
    int ans = 0;
    for ( j = 0; j < 400; j++ )
        ans = max( ans, 2 * min( a[j], b[j] ) );
    printf( "%d", ans );
    return 0;
}