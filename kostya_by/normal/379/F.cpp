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

int n = 4, q, v1 = 2, v2 = 3;
int tin[ 1000100 ], tout[ 1000100 ], timer = 0, d[ 1000100 ], p[ 21 ][ 1000100 ];
vector< int > graf[ 1000100 ];

void dfs( int v )
{
    tin[v] = ++timer;
    for ( int i = 0; i < graf[v].size(); i++ ) dfs( graf[v][i] );
    tout[v] = timer;
    //cout << v << " " << d[v] << " " << tin[v] << " " << tout[v] << "\n";
}

bool is_parent( int parent, int child )
{
    return ( tin[parent] <= tin[child] && tout[child] <= tout[parent] );
}

int lca( int v1, int v2 )
{
    if ( is_parent( v1, v2 ) ) return v1;
    if ( is_parent( v2, v1 ) ) return v2;
    for ( int i = 20; i >= 0; i-- )
        if ( !is_parent( p[i][v1], v2 ) )
            v1 = p[i][v1];
    return p[0][v1]; 
}

int fun( int v1, int v2 )
{
    //cout << v1 << " " << v2 << " " << lca(v1, v2) << " " << d[v1] + d[v2] - d[ lca(v1, v2) ] << "\n";
    return d[v1] + d[v2] - 2 * d[ lca(v1, v2) ];
}

void try1( int a, int b )
{
    int f1 = fun( v1, v2 );
    int f2 = fun( a, b );
    if ( f1 >= f2 ) return;
    v1 = a;
    v2 = b;
}

void check( int v )
{
    int tv1 = v1;
    int tv2 = v2;
    try1( v, tv1 );
    try1( v, tv2 );
}

int main (int argc, const char * argv[])
{
    d[1] = 0;
    d[2] = d[3] = d[4] = 1;
    for ( int i = 0; i < 21; i++ ) p[i][1] = p[i][2] = p[i][3] = p[i][4] = 1;
    graf[1].pb( 2 ); graf[1].pb( 3 ); graf[1].pb( 4 );
    scanf("%d", &q);
    for ( int it = 0; it < q; it++ )
    {
        int v; scanf("%d", &v);
        d[n + 1] = d[v] + 1; p[0][n + 1] = v; for ( int i = 1; i < 21; i++ ) p[i][n + 1] = p[i - 1][ p[i - 1][n + 1] ];
        d[n + 2] = d[v] + 1; p[0][n + 2] = v; for ( int i = 1; i < 21; i++ ) p[i][n + 2] = p[i - 1][ p[i - 1][n + 2] ];
        graf[v].pb( n + 1 );
        graf[v].pb( n + 2 );
        n += 2;
    }
    dfs( 1 );
    n = 4;
    for ( int it = 0; it < q; it++ )
    {
        check( n + 1 );
        check( n + 2 );
        n += 2;
        printf("%d\n", fun( v1, v2 ));
    }
    return 0;
}