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

int n, m, q, p[ 300300 ], center[ 300300 ], radius[ 300300 ], value[ 300300 ];
int id = 0;
vector< int > graph[ 300300 ];
vector< int > cur;
bool used[ 300300 ];
int f[ 300300 ], g[ 300300 ], h[ 300300 ];

void dfs( int v )
{
    used[ v ] = true;
    cur.pb( v );
    f[ v ] = 0;
    vector< int > t;
    for ( int i = 0; i < graph[v].size(); i++ )
    {
        int next = graph[v][i];
        if ( used[ next ] ) continue;
        dfs( next );
        f[ v ] = max( f[ v ], f[ next ] + 1 );
        t.pb( f[ next ] + 1 );
    } 
    sort( t.begin(), t.end(), greater< int >() );
    for ( int i = 0; i < min( 2, (int)t.size() ); i++ ) h[v] += t[i]; 
}

void dfs2( int v, int gg )
{
    g[v] = gg;
    used[ v ] = true;
    vector< int > cur; cur.pb( gg );
    for ( int i = 0; i < graph[v].size(); i++ )
    {
        int next = graph[v][i];
        if ( used[ next ] ) continue;
        cur.pb( f[ next ] + 1 );
    } 
    sort( cur.begin(), cur.end(), greater< int >() );
    for ( int i = 0; i < graph[v].size(); i++ )
    {
        int next = graph[v][i];
        if ( used[ next ] ) continue;
        int gg = cur[ 0 ];
        if ( gg == f[ next ] + 1 ) gg = cur[ 1 ];
        dfs2( next, gg + 1 );
    } 
}

int get_prev( int v )
{
    if ( v == p[v] ) return v;
    p[v] = get_prev( p[v] );
    return p[v];
}

int unite( int a, int b )
{
    a = get_prev( a );
    b = get_prev( b );
    assert( a != b );
    if ( rand() & 1 ) swap( a, b );
    p[ a ] = b;
    int ca = center[ a ];
    int cb = center[ b ];
    value[ b ] = max( value[ a ], max( value[ b ], radius[ a ] + 1 + radius[ b ] ) );
    int ra = max( radius[ a ], 1 + radius[ b ] );
    int rb = max( radius[ b ], 1 + radius[ a ] );
    if ( ra <= rb )
    {
        center[ b ] = ca;
        radius[ b ] = ra;
    } else
    {
        center[ b ] = cb;
        radius[ b ] = rb;
    }
}

int main (int argc, const char * argv[])
{
    srand( 2318 );
    scanf("%d%d%d", &n, &m, &q);
    for ( int i = 1; i <= n; i++ )
    {
        p[i] = i;
        center[i] = i;
        radius[i] = 0;
        value[i] = 0;
    }
    for ( int i = 1; i <= m; i++ )
    {
        int a, b; scanf("%d%d", &a, &b);
        graph[ a ].pb( b );
        graph[ b ].pb( a );
    }
    for ( int i = 1; i <= n; i++ )
    {
        if ( used[i] ) continue;
        id++; cur.clear();
        dfs( i );
        for ( int j = 0; j < cur.size(); j++ ) used[ cur[j] ] = false;
        dfs2( i, 0 );
        /*for ( int j = 0; j < cur.size(); j++ )
        {
            cout << cur[j] << " " << f[ cur[j] ] << " " << g[ cur[j] ] << " " << h[ cur[j] ] << "\n";;
        }
        cout << "--------------\n";*/
        int v = i;
        for ( int j = 0; j < cur.size(); j++ )
        {
            int u = cur[j];
            if ( max( f[u], g[u] ) < max( f[v], g[v] ) ) v = u;
            p[u] = i;
            // value[u] = max( value[u], h[u] ); WRONG
            value[i] = max( value[i], h[u] );
        }
        center[i] = v;
        radius[i] = max( f[v], g[v] );
    }
    for ( int it = 1; it <= q; it++ )
    {
        int id; scanf("%d", &id);
        if ( id == 1 )
        {
            int v; scanf("%d", &v);
            printf("%d\n", value[ get_prev( v ) ]);
        } else
        {
            int u, v; scanf("%d%d", &u, &v);
            u = get_prev( u );
            v = get_prev( v );
            if ( u == v ) continue;
            unite( center[u], center[v] );
        }
    }
    return 0;
}

/*
8 6 0
1 2
1 8
2 3
3 4
4 5
6 7
*/