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

int n, p[ 1000100 ], f[ 1000100 ];
pair< int, int > max_child[ 1000100 ];

void upd( int v, int u )
{
    if ( max_child[v].first == 0 )
    {
        max_child[v].first = u;
        return;
    }
    if ( max_child[v].second == 0 )
    {
        if ( max_child[v].first == u ) return;
        max_child[v].second = u;
        if ( f[ max_child[v].first ] < f[ max_child[v].second ] ) swap( max_child[v].first, max_child[v].second );
        return;
    }
    if ( u == max_child[v].second || u == max_child[v].first )
    {
        if ( f[ max_child[v].first ] < f[ max_child[v].second ] ) swap( max_child[v].first, max_child[v].second );
        return;
    }
    if ( f[ max_child[v].second ] < f[ u ] ) 
    {
        max_child[v].second = u;
        if ( f[ max_child[v].first ] < f[ max_child[v].second ] ) swap( max_child[v].first, max_child[v].second );
    }
}

int fun( int v )
{
    if ( v == 1 )
    {
        if ( max_child[v].first == 0 ) return 0;
        return f[ max_child[v].first ];
    }
    if ( max_child[v].first == 0 ) return 1;
    if ( max_child[v].second == 0 ) return f[ max_child[v].first ];
    return max( f[ max_child[v].first ], f[ max_child[v].second ] + 1 );
} 

void solve( int v )
{
    if ( fun( v ) == f[v] ) return;
    f[v] = fun(v);
    if ( v == 1 ) return;
    upd( p[v], v );
    solve( p[v] );
}

int main (int argc, const char * argv[])
{
    f[1] = 0;
    scanf("%d", &n);
    for ( int i = 2; i <= n + 1; i++ )
    {
        scanf("%d", &p[i]);
        f[i] = 1;
        upd( p[i], i );
        solve( p[i] );
        //full_upd();
        //cout << max_child[1].first << " " << max_child[1].second << "\n";
        //cout << "Level " << i << "\n";
        //for ( int j = 1; j <= i; j++ ) cout << f[ max_child[j].first ] << " " << f[ max_child[j].second ] << " " << f[j] << "\n";
        //cout << "----------\n";
        printf("%d ", f[1]);
    }
    return 0;
}