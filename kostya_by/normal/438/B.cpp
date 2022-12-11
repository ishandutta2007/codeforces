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

struct edge
{
    int a, b, c;
    edge( int a = 0, int b = 0, int c = 0 ) : a( a ), b( b ), c( c ) {};
};

bool cmp( edge a, edge b )
{
    return a.c > b.c;
}

edge e[ 100100 ]; 
int n, m, cost[ 100100 ], p[ 100100 ], sz[ 100100 ];
vector< int > graph[ 100100 ];

int get_prev( int v )
{
    if ( p[v] == v ) return v;
    p[v] = get_prev( p[v] );
    return p[v];
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for ( int i = 1; i <= n; i++ ) scanf("%d", &cost[i]), p[i] = i, sz[i] = 1;
    for ( int i = 1; i <= m; i++ )
    {
        scanf("%d%d", &e[i].a, &e[i].b);
        e[i].c = min( cost[ e[i].a ], cost[ e[i].b ] );
    }
    long long fi = 0;
    sort( e + 1, e + m + 1, cmp ); 
    for ( int i = 1; i <= m; i++ )
    {
        int a = e[i].a;
        int b = e[i].b;
        int c = e[i].c;
        int pa = get_prev( a );
        int pb = get_prev( b );
        if ( pa == pb ) continue;   
        fi += 2ll * c * sz[ pa ] * sz[ pb ];
        sz[ pa ] += sz[ pb ];
        p[ pb ] = pa;  
    }

    long long se = 1ll * n * (n - 1);
    long double result = (long double)fi / (long double)se;

   // cout << fi << " " << se << "\n";

    cout << fixed << setprecision( 6 ) << result << "\n";

    return 0;
}