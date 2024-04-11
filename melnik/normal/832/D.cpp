#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
using namespace std;

#define pb push_back

vector < int > edge[100500];
int used[100500];
int up[100500][20];
int tin[100500];
int tout[100500];
int h[100500];
int timer;

void dfs( int v, int anc, int height ) {
    h[v] = height++;
    tin[v] = ++timer;
    up[v][0] = anc;
    used[v] = true;
    for ( int j = 1; j < 20; j++ )
        up[v][j] = up[up[v][j - 1]][j - 1];
    for ( int to : edge[v] ) {
        if ( used[to] )
            continue;
        dfs( to, v, height );
    }
    tout[v] = ++timer;
}

bool isUpper( int u, int v ) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int getLca( int u, int v ) {
    if ( isUpper( u, v ) )
        return u;
    if ( isUpper( v, u ) )
        return v;
    for ( int j = 19; j >= 0; j-- )
        if ( !isUpper( up[u][j], v ) )
            u = up[u][j];
    return up[u][0];
}



int main()
{

//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
    int n, q;
    scanf ( "%d%d", &n, &q );
    for ( int j = 2; j <= n; j++ ) {
        int v;
        scanf ( "%d", &v );
        edge[j].pb( v );
        edge[v].pb( j );
    }
    tin[0] = -1;
    tout[0] = 2e9;
    dfs( 1, 0, 0 );
    while ( q-- ) {
        vector < int > a;
        a.pb( -1 );
        int x, y, z;
        scanf ( "%d%d%d", &x, &y, &z );
        a.pb( x );
        a.pb( y );
        a.pb( z );
        sort( a.begin(), a.end() );
        int ans = 0;
        while ( a[0] == -1 ) {
            int cnt = 0;
            int v = getLca( a[1], a[3] );
            cnt += h[a[1]] + h[a[3]] - 2 * h[v] + 1;

            v = getLca( a[2], a[3] );
            cnt += h[a[2]] + h[a[3]] - 2 * h[v] + 1;

            v = getLca( a[1], a[2] );
            cnt -= h[a[1]] + h[a[2]] - 2 * h[v];
            ans = max( ans, cnt /   2 );
//            cout << a[0] << a[1] << a[2] << a[3] << endl;
            next_permutation( a.begin(), a.end() );
        }
        printf( "%d\n", ans );
    }
    return 0;
}