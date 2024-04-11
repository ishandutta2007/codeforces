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

int n, m, a[ 200200 ], pls[ 200200 ], tin[ 200200 ], tout[ 200200 ], h[ 200200 ], timer = 0;
int order[ 200200 ], hh = 0, p[ 200200 ];
vector< int > graf[ 200200 ];
vector< pair< int, int > > q;

void dfs( int v, int prev )
{
    tin[v] = ++timer;
    p[v] = prev;
    for ( int i = 0; i < graf[v].size(); i++ )
    {
        int next = graf[v][i];
        if ( next == prev ) continue;
        h[next] = h[v] ^ 1;
        dfs( next, v );
    }
    tout[v] = timer;
    order[ ++hh ] = v;
}

void rebuild()
{
    for ( int i = 0; i < q.size(); i++ ) pls[ q[i].first ] += q[i].second;
    q.clear();
    for ( int i = 1; i <= n; i++ )
    {
        int v = order[i];
        pls[v] -= pls[ p[v] ];
        a[v] += pls[v];
    }
    for ( int i = 1; i <= n; i++ ) pls[i] = 0;
}

int main (int argc, const char * argv[])
{
    scanf("%d%d", &n, &m);
    for ( int i = 1; i <= n; i++ ) scanf("%d", &a[i]);
    for ( int i = 1; i < n; i++ )
    {
        int a, b; scanf("%d%d", &a, &b);
        graf[a].pb( b );
        graf[b].pb( a ); 
    }
    timer = 0;
    h[1] = 1;
    dfs( 1, 0 );
    reverse( order + 1, order + n + 1 );
    while ( m-- )
    {
        int _type; scanf("%d", &_type);
        if ( _type == 1 ) 
        {
            int x, val; scanf("%d%d", &x, &val);
            q.pb( mp( x, val ) );
            if ( q.size() >= 300 ) rebuild();
        }
        if ( _type == 2 )
        {
            int v, res; scanf("%d", &v);
            res = a[v];
            for ( int i = 0; i < q.size(); i++ )
            {
                int x = q[i].first;
                int val = q[i].second;
                if ( tin[x] <= tin[v] && tout[v] <= tout[x] )
                {
                    if ( h[x] == h[v] ) res += val; else res -= val;
                }
            }
            printf("%d\n", res);
        }
    }
    return 0;
}