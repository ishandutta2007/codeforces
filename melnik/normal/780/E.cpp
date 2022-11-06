#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 200500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

vector < int > ans[maxn];
int used[maxn];
int id, have, maxCnt;
vector < int > edge[maxn];

void update() {
    if ( have == maxCnt ) {
        have = 0;
        ++id;
    }
}

void dfs( int v ) {
    used[v] = true;
    int sz = edge[v].size();
    ans[id].pb( v );
    ++have;
    update();
    for ( int j = 0; j < sz; j++ ) {
        int to = edge[v][j];
        if ( used[to] )
            continue;
        dfs( to );
        ans[id].pb( v );
        ++have;
        update();
    }
}

int main()
{
    srand( time( NULL ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio( false );
    int n, m, k;
    scanf ( "%d%d%d", &n, &m, &k );
    for ( int j = 0; j < m; j++ ) {
        int u, v;
        scanf ( "%d%d", &u, &v );
        edge[u].pb( v );
        edge[v].pb( u );
    }
    int cnt = ( 2 * n + k - 1 ) / k;
    id = 1;
    have = 0;
    maxCnt = cnt;
    dfs( 1 );
    for ( int j = 1; j <= k; j++ ) {
        int sz = ans[j].size();
        if ( sz == 0 ) {
            ++sz;
            ans[j].pb( 1 );
        }
        printf ( "%d", sz );
        for ( int i = 0; i < sz; i++ )
            printf ( " %d", ans[j][i] );
        printf ( "\n" );
    }
    return 0;
}