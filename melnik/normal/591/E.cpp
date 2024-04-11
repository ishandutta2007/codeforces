#include <iostream>
#include <fstream>
#include <stdio.h>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <ext\hash_set>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <time.h>
#include <ctime>
#include <iterator>
#include <cstdio>


using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 1010;
const int inf = 2e9;
const double eps = 1e-10;

pair < int, int > i[maxn][maxn];
int used[maxn * maxn];
int dist[maxn * maxn][3];
queue < pair < int, int > > for_bfs;

int check ( char t ) {
    if ( t == '#' ) return 0;
    if ( t == '1' ) return 1;
    if ( t == '2' ) return 2;
    if ( t == '3' ) return 3;
    return 4;
}


list < int > edge[maxn * maxn];
list < int >::iterator o;

void add_edge ( int a, int b ) {
    edge[a].pb( b );
}

void bfs ( int num ) {
    while ( !for_bfs.empty() ) {
        int v = for_bfs.front().f;
        int s = for_bfs.front().s;
        for_bfs.pop();
        dist[v][num] = s;
        int sz = edge[v].size();
        o = edge[v].begin();
        for ( ; o != edge[v].end(); o++ ) {
            if ( !used[*o] ) {
                for_bfs.push ( mp ( *o, s + 1 ) );
                used[*o] = 1;
            }
        }
    }
}


int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
    int n, m, j, k;
    ll ans;
    scanf ( "%d%d", &n, &m );
    char t;
    scanf ( "%c", &t );
    int z = 5;
    for ( j = 0; j < maxn; j++ )
        for ( k = 0; k < maxn; k++ ) {
            i[j][k].f = 0;
            i[j][k].s = z;
            z++;
        }
    for ( j = 1; j <= n; j++ ) {
        for ( k = 1; k <= m; k++ ) {
            char e;
            scanf ( "%c", &e );
            i[j][k].f = check( e );
            if ( i[j][k].f < 4 ) i[j][k].s = i[j][k].f;
        }
        scanf ( "%c", &t );
    }
//    for ( j = 1; j <= n; j++ ) {
//        for ( k = 1; k <= m; k++ )
//            printf ( "%d ", i[j][k].s );
//        printf ( "\n" );
//    }
    for ( j = 0; j < maxn; j++ )
        for ( k = 0; k < maxn; k++ ) {
            if ( i[j][k].f == 0 ) continue;
            if ( i[j][k + 1].f != 0 &&
                ( i[j][k + 1].f == 4 || i[j][k].f != i[j][k + 1].f ) )
                    add_edge( i[j][k].s, i[j][k + 1].s );
            if ( i[j][k - 1].f != 0 &&
                ( i[j][k - 1].f == 4 || i[j][k].f != i[j][k - 1].f ) )
                    add_edge( i[j][k].s, i[j][k - 1].s );
            if ( i[j - 1][k].f != 0 &&
                ( i[j - 1][k].f == 4 || i[j][k].f != i[j - 1][k].f ) )
                    add_edge( i[j][k].s, i[j - 1][k].s );
            if ( i[j + 1][k].f != 0 &&
                ( i[j + 1][k].f == 4 || i[j][k].f != i[j + 1][k].f ) )
                    add_edge( i[j][k].s, i[j + 1][k].s );
        }
//    printf ( "\n" );
//    for ( j = 0; j < maxn * maxn; j++ ) {
//        if ( edge[j].size() != 0 ){
//            edge[j].sort();
//            edge[j].unique();
//            printf ( "%d    ", j );
//            o = edge[j].begin();
//            for ( ; o != edge[j].end(); o++ )
//                printf ( "%d ", *o );
//                printf ( "\n" );
//        }
//    }
    for ( j = 0; j < maxn * maxn; j++ ) {
        edge[j].sort();
        edge[j].unique();
    }
    ans = 1LL * inf * inf;
    for ( j = 0; j < maxn * maxn; j++ ) {
        used[j] = 0;
        dist[j][0] = inf;
        dist[j][1] = inf;
        dist[j][2] = inf;
    }
    used[1] = 1;
    for_bfs.push( mp ( 1, 0 ) );
    bfs ( 0 );

    for ( j = 0; j < maxn * maxn; j++ ) {
        used[j] = 0;
    }
    used[2] = 1;
    for_bfs.push( mp ( 2, 0 ) );
    bfs ( 1 );

    for ( j = 0; j < maxn * maxn; j++ ) {
        used[j] = 0;
    }
    used[3] = 1;
    for_bfs.push( mp ( 3, 0 ) );
    bfs ( 2 );

    for ( j = 0; j < maxn * maxn; j++ ) {
        ans = min ( 1LL * ans, 1LL * dist[j][0] + dist[j][1] + dist[j][2] - 2LL );
    }
//    for ( j = 1; j < 4; j++ ) {
//        ans = min ( 1LL * ans, 1LL * dist[j][0] + dist[j][1] + dist[j][2] - 2LL );
//    }

    if ( ans >= 1e9 ) printf ( "-1" ); else
        printf ( "%I64d", ans );

    return 0;
}