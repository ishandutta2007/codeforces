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

int n, q, a[ 100100 ], tree[ 400400 ];
long long fw[ 100100 ];

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
    tree[v] = tree[v + v];
    if ( a[ tree[v + v] ] < a[ tree[v + v + 1] ] ) tree[v] = tree[v + v + 1];
}

void query1( int v, int l, int r, int pos )
{
    if ( l == r ) return;
    int x = (l + r) / 2;
    if ( pos <= x ) query1( v + v, l, x, pos ); else query1( v + v + 1, x + 1, r, pos );
    tree[v] = tree[v + v];
    if ( a[ tree[v + v] ] < a[ tree[v + v + 1] ] ) tree[v] = tree[v + v + 1];
}

int query2( int v, int l, int r, int ll, int rr )
{
    if ( l == ll && rr == r ) return tree[v];
    int x = (l + r) / 2;
    int result = -1;
    if ( ll <= x ) 
    {
        int tmp = query2( v + v, l, x, ll, min( x, rr ) );
        if ( result == -1 ) result = tmp;
        if ( a[result] < a[tmp] ) result = tmp;
    }
    if ( x + 1 <= rr )
    {
        int tmp = query2( v + v + 1, x + 1, r, max( x + 1, ll ), rr );
        if ( result == -1 ) result = tmp;
        if ( a[result] < a[tmp] ) result = tmp;
    }
    return result;
}

void modify( int pos, long long delta )
{
    while ( pos < 100100 )
    {
        fw[ pos ] += delta;
        pos = pos + pos - ( pos & ( pos - 1 ) );
    } 
}

long long pref( int pos )
{
    long long result = 0;
    while ( pos )
    {
        result += fw[ pos ];
        pos = pos & ( pos - 1 );
    }
    return result;
}

long long fsum( int l, int r )
{
    return pref(r) - pref(l - 1);
}

int main (int argc, const char * argv[])
{
    scanf("%d%d", &n, &q);
    for ( int i = 1; i <= n; i++ )
    {
        scanf("%d", &a[i]);
        modify( i, a[i] ); 
    }
    init( 1, 1, n );
    for ( int it = 0; it < q; it++ )
    {
        int _type; scanf("%d", &_type);
        if ( _type == 1 )
        {
            int l, r; scanf("%d%d", &l, &r);
            printf("%I64d\n", fsum( l, r ) );
        }
        if ( _type == 2 )
        {
            int l, r, x; scanf("%d%d%d", &l, &r, &x);
            while ( true )
            {
                int pos = query2( 1, 1, n, l, r );
                if ( a[pos] < x ) break;
                modify( pos, -a[pos] );
                a[pos] %= x;
                modify( pos, a[pos] );
                query1( 1, 1, n, pos ); 
            }
        }
        if ( _type == 3 )
        {
            int pos, value; scanf("%d%d", &pos, &value);
            modify( pos, -a[pos] );
            a[pos] = value;
            modify( pos, a[pos] );
            query1( 1, 1, n, pos ); 
        }
    }
    return 0;
}