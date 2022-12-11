#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <stack>
#include <bitset>
#include <sstream>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

struct change
{
    int level, l, r, x;
    change() : level( 0 ), l( 0 ), r( 0 ), x( 0 ) {};
};

int n, m, cnt[ 7070 ], h = 0;
pair< int, int > sparse[ 15 ][ 200200 ];
change c[ 7070 ];
int f[ 1000005 ], active_id = 0;

pair< int, int > range( int v, int k )
{
    pair< int, int > cur = mp( v, v );
    for ( int i = 0; i < 15; i++ )
        if ( k & ( 1 << i ) )
        {
            int left = sparse[ i ][ cur.first ].first;
            int right = sparse[ i ][ cur.second ].second;
            cur = mp( left, right );
        }
    return cur;
}

int query( int level, int pos )
{
    active_id++;
    int res = 0;
    for ( int i = 1; i <= h; i++ )
    {
        if ( f[ c[i].x ] == active_id ) continue;
        int diff = c[i].level - level;
        if ( diff < 0 ) continue;
        int l1 = c[i].l, r1 = c[i].r;
        pair< int, int > cur = range( pos, diff );
        int l2 = cur.first, r2 = cur.second;
        if ( max( l1, l2 ) > min( r1, r2 ) ) continue;
        res += 1;
        f[ c[i].x ] = active_id;
    }
    return res;
}

int main (int argc, const char * argv[])
{
    scanf("%d", &n);
    cnt[1] = 1;
    for ( int i = 1; i < n; i++ )
    {
        cnt[i + 1] = cnt[i];
        for ( int j = 1; j <= cnt[i]; j++ ) if ( ( j & (j - 1) ) == 0 ) cnt[i + 1]++;
    }
    for ( int i = 1; i <= cnt[n]; i++ )
    {
        if ( i & (i - 1) )
        {
            sparse[0][i] = mp( cnt[n + 1] + 1, cnt[n + 1] + 1 );
            cnt[n + 1]++;
            continue;
        }
        sparse[0][i] = mp( cnt[n + 1] + 1, cnt[n + 1] + 2 );
        cnt[n + 1] += 2;
        continue;
    }
    for ( int pt = 1; pt < 15; pt++ )
        for ( int i = 1; i <= cnt[n]; i++ )
        {
            pair< int, int > p = sparse[pt - 1][i];
            int left = sparse[pt - 1][ p.first ].first;
            int right = sparse[pt - 1][ p.second ].second;
            sparse[pt][i] = mp( left, right );
        }
    scanf("%d", &m);
    for ( int it = 1; it <= m; it++ )
    {
        int tp; scanf("%d", &tp);
        if ( tp == 1 )
        {
            int level, l, r, x; scanf("%d%d%d%d", &level, &l, &r, &x);
            change cur;
            cur.level = level;
            cur.l = l;
            cur.r = r;
            cur.x = x;
            c[ ++h ] = cur;
            continue;
        }
        int level, pos; scanf("%d%d", &level, &pos);
        printf("%d\n", query( level, pos ));
    }
    return 0;
}