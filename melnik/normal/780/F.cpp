#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 505;
const int inf = 1e9;
const double eps = 1e-8;
const int base = 1073676287;

vector < ull > f[maxn][65];
vector < ull > g[maxn][65];

vector < pair < int, int > > edge[maxn];
int used[maxn];
ll st[maxn];

ll dp[maxn][65][2];

int main()
{
    srand( time( NULL ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio( false );
    for ( int j = 0; j < maxn; j++ )
        for ( int i = 0; i < 65; i++ )
            for ( int y = 0; y < 8; y++ ) {
                f[j][i].pb( 0 );
                g[j][i].pb( 0 );
            }
    st[0] = 1;
    for ( int j = 1; j < maxn; j++ )
        st[j] = 2LL * st[j - 1];
    int n, m;
    scanf ( "%d%d", &n, &m );
    for ( int j = 0; j < m; j++ ) {
        int u, v, t;
        scanf ( "%d%d%d", &u, &v, &t );
        edge[u].pb( mp( v, t ) );
    }
    for ( int j = 1; j <= n; j++ ) {
        int sz = edge[j].size();
        for ( int i = 0; i < sz; i++ ) {
            int to = edge[j][i].f;
            int type = edge[j][i].s;

            int pos = ( to - 1 ) / 64;
            int id = ( to - 1 ) % 64;

            if ( type == 0 )
                f[j][0][pos] |= 1ULL << id;
            else
                g[j][0][pos] |= 1ULL << id;
        }
    }
    int u, sz, sz2;
    for ( int j = 1; j <= 60; j++ )
        for ( int v = 1; v <= n; v++ ) {
            for ( int pos = 0; pos < 8; pos++ )
                for ( int id = 0; id < 64; id++ ) {
                    if ( ( f[v][j - 1][pos] & ( 1ULL << id ) ) == 0ULL )
                        continue;
                    u = 1 + pos * 64 + id;
                    for ( int y = 0; y < 8; y++ )
                        f[v][j][y] |= g[u][j - 1][y];
                }


            for ( int pos = 0; pos < 8; pos++ )
                for ( int id = 0; id < 64; id++ ) {
                    if ( ( g[v][j - 1][pos] & ( 1ULL << id ) ) == 0ULL )
                        continue;
                    u = 1 + pos * 64 + id;
                    for ( int y = 0; y < 8; y++ )
                        g[v][j][y] |= f[u][j - 1][y];
                }
        }

    for ( int j = 0; j < maxn; j++ )
        for ( int i = 0; i < 65; i++ )
            dp[j][i][0] = -4LL * inf * inf;
    for ( int j = 60; j >= 0; j-- )
        for ( int v = 1; v <= n; v++ ) {
            sz = f[v][j].size();
            dp[v][j - 1][0] = max( dp[v][j - 1][0], dp[v][j][0] );
            dp[v][j - 1][1] = max( dp[v][j - 1][1], dp[v][j][1] );
            for ( int pos = 0; pos < 8; pos++ )
                for ( int id = 0; id < 64; id++ ) {
                    if ( ( f[v][j][pos] & ( 1ULL << id ) ) == 0ULL )
                        continue;
                    int to = 1 + pos * 64 + id;
                    ll cnt = dp[v][j][1] + st[j];
                    dp[to][j - 1][0] = max( dp[to][j - 1][0], cnt );
                }
            for ( int pos = 0; pos < 8; pos++ )
                for ( int id = 0; id < 64; id++ ) {
                    if ( ( g[v][j][pos] & ( 1ULL << id ) ) == 0ULL )
                        continue;
                    int to = 1 + pos * 64 + id;
                    ll cnt = dp[v][j][0] + st[j];
                    dp[to][j - 1][1] = max( dp[to][j - 1][1], cnt );
                }
        }
    ll ans = 0LL;
    for ( int j = 0; j < maxn; j++ )
        for ( int i = 0; i < 65; i++ )
            ans = max( ans, max( dp[j][i][0], dp[j][i][1] ) );
    if ( ans > 1LL * inf * inf )
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}