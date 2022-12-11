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

int n, m, s, a[ 100100 ], b[ 100100 ], c[ 100100 ], w[ 100100 ];
int order[ 100100 ], num[ 100100 ];
int tree[ 400400 ];

class cmp
{
public:
    bool operator()( int i, int j )
    {
        return a[i] < a[j];
    }
};

bool cmp1( int i, int j )
{
    return b[i] < b[j];
}

priority_queue< int, vector< int >, cmp > pq;

void init( int v, int l, int r )
{
    if ( l == r )
    {
        tree[v] = l;
        return;
    }
    int x = (l + r) / 2;
    init( v + v, l, x );
    init( v + v + 1, x + 1, r );
    if ( c[ order[ tree[v + v] ] ] < c[ order[ tree[v + v + 1] ] ] ) tree[v] = tree[v + v]; else tree[v] = tree[v + v + 1];
} 

int get_min( int v, int ll, int rr, int l, int r )
{
    if ( l == ll && rr == r ) return tree[v];
    int xx = (ll + rr) / 2;
    int id1 = n; if ( l <= xx )     id1 = get_min( v + v, ll, xx, l, min( xx, r ) );
    int id2 = n; if ( xx + 1 <= r ) id2 = get_min( v + v + 1, xx + 1, rr, max( xx + 1, l ), r );
    if ( c[ order[ id1 ] ] < c[ order[ id2 ] ] ) return id1;
    return id2;
}

void modify( int v, int l, int r, int pos )
{
    if ( l == r )
    {
        tree[v] = n;
        return;
    }
    int x = (l + r) / 2;
    if ( pos <= x ) modify( v + v, l, x, pos ); else modify( v + v + 1, x + 1, r, pos );
    if ( c[ order[ tree[v + v] ] ] < c[ order[ tree[v + v + 1] ] ] ) tree[v] = tree[v + v]; else tree[v] = tree[v + v + 1];
}

int get_pos( int id )
{
    int l = 1, r = n - 1, res = n;
    while ( l <= r )
    {
        int x = (l + r) / 2;
        if ( b[ order[x] ] >= a[id] )
        {
            res = min( res, x );
            r = x - 1;
        } else l = x + 1;
    }
    return res;
}

bool check( int x )
{
    while ( pq.size() ) pq.pop();
    for ( int i = 1; i <= m; i++ ) pq.push( i );
    for ( int i = 1; i < n; i++ ) num[i] = x; num[n] = m;
    init( 1, 1, n );
    int wid = 0;
    while ( pq.size() )
    {
        int id = pq.top(); pq.pop();
        if ( num[ order[ wid ] ] > 0 )
        {
            w[id] = wid;
            num[ order[ wid ] ]--;
            continue;
        } 
        if ( wid != 0 ) modify( 1, 1, n, wid );
        int ll = get_pos( id ), rr = n;
        //cout << id << " " << ll << " " << rr << "\n"; 
        wid = w[id] = get_min( 1, 1, n, ll, rr );
        num[ order[ w[id] ] ]--;
    }
    int res = 0;
    for ( int i = 1; i < n; i++ )
    {
        if ( num[i] < x ) res += c[i];
        if ( res > s ) return false;
    }
    if ( num[n] != m ) return false;
    //cout << x << " " << res << ": "; for ( int i = 1; i <= n; i++ ) cout << c[i] << " "; cout << "\n";
    return true;
}

int main (int argc, const char * argv[])
{
    scanf("%d%d%d", &n, &m, &s);
    for ( int i = 1; i <= m; i++ ) scanf("%d", &a[i]);
    for ( int i = 1; i <= n; i++ ) scanf("%d", &b[i]); b[n + 1] = 1000000000;
    for ( int i = 1; i <= n; i++ ) scanf("%d", &c[i]); c[n + 1] = s + 1;
    for ( int i = 1; i <= n; i++ ) order[i] = i; order[n + 1] = n + 1;
    n++;
    sort( order + 1, order + n + 1, cmp1 );
    if ( !check( m ) )
    {
        puts("NO");
        return 0;
    }
    int l = 1, r = m - 1, res = m;
    while ( l <= r )
    {
        int x = (l + r) / 2;
        if ( check( x ) )
        {
            res = min( res, x );
            r = x - 1;
        } else l = x + 1;
    }
    check( res );
    puts("YES");
    for ( int i = 1; i <= m; i++ ) printf("%d ", order[ w[i] ]);
    return 0;
}