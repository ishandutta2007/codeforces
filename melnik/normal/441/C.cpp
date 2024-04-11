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

vector < pair < int, int > > ans[maxn];

inline void next( int &x, int &y, int n, int m ) {
    if ( x & 1 ) {
        ++y;
        if ( y > m ) {
            ++x;
            --y;
        }
        return;
    }
    --y;
    if ( !y ) {
        ++y;
        ++x;
    }    
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, m, k;
    scanf ( "%d%d%d", &n, &m, &k );
    int x = 1, y = 1;
    for ( int j = 0; j < k; j++ ) {
        if ( j != k - 1 ) {
            ans[j].pb( mp( x, y ) );
            next( x, y, n, m );
            ans[j].pb( mp( x, y ) );
            next( x, y, n, m );
        }
        if ( j == k - 1 ) {
            while ( x <= n && y <= m ) {
                ans[j].pb( mp( x, y ) );
                next( x, y, n, m );
            }
        }
    }
    for ( int j = 0; j < k; j++ ) {
        int sz = ans[j].size();
        printf( "%d\n", sz );
        for ( int i = 0; i < sz; i++ )
            printf( "%d %d ", ans[j][i].f, ans[j][i].s );
        printf( "\n" );
    }
    return 0;
}