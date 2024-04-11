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

int ans[maxn];
vector < int > edge[maxn];

void dfs( int v, int anc ) {
    int timer = 1;
    int sz = edge[v].size();
    for ( int j = 0; j < sz; j++ ) {
        int to = edge[v][j];
        if ( to == anc )
            continue;
        while ( timer == ans[v] || timer == ans[anc] )
            ++timer;
        ans[to] = timer++;
        dfs( to, v );
    }
}

int main()
{
    srand( time( NULL ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio( false );
    int n;
    scanf ( "%d", &n );
    for ( int j = 1; j < n; j++ ) {
        int u, v;
        scanf ( "%d%d", &u, &v );
        edge[u].pb( v );
        edge[v].pb( u );
    }
    ans[1] = 1;
    dfs( 1, 0 );
    int cnt = 0;
    for ( int j = 0; j < maxn; j++ )
        cnt = max( cnt, ans[j] );
    printf ( "%d\n", cnt );
    for ( int j = 1; j <= n; j++ )
        printf ( "%d ", ans[j] );
    return 0;
}