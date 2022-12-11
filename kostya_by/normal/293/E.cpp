#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

#define pb push_back
#define mp make_pair
typedef unsigned long long ull;

const long long inf = 1e18;
const long double eps = 1e-9;

long long answer = 0;
int n, L, W, f[ 100100 ], g[ 100100 ], root;
int depth[ 100100 ], dist[ 100100 ];
vector< pair< int, int > > graf[ 100100 ];
pair< int, int > v1[ 100100 ], v2[ 100100 ];
int h1, h2;
vector< int > s[ 100100 ];
int cm[ 100100 ], sm[ 100100 ], hc, hs;
int subtree[ 100100 ], st;
bool bad[ 100100 ];

class cmp
{
    public:
        bool operator()( int a, int b )
        {
            if ( s[a].size() > s[b].size() ) return true;
            return false;
        }
};

priority_queue< int, vector< int >, cmp > cur;

bool cmp1( pair< int, int > a, pair< int, int > b )
{
    if ( a.first < b.first ) return true;
    return false;
}

bool cmp2( pair< int, int > a, pair< int, int > b )
{
    if ( a.first > b.first ) return true;
    return false;
}

bool cmp3( pair< int, int > a, pair< int, int > b )
{
    if ( a.second < b.second ) return true;
    return false;
}

int fsum( int id )
{
    int res = 0;
    while ( id > 0 )
    {
        res += sm[id];
        id = id & ( id - 1 );
    }
    return res;
}

void modify( int id )
{
    while ( id < hs )
    {
        sm[ id ]++;
        id = 2 * id - ( id & ( id - 1 ) );
    }
}

void unite( int a, int b )
{
    h1 = h2 = 0;
    for ( int i = 0; i < s[a].size(); i++ )
    {
        int id = s[a][i];
        v1[ h1++ ] = mp( depth[id], dist[id] );
    }
    for ( int i = 0; i < s[b].size(); i++ )
    {
        int id = s[b][i];
        v2[ h2++ ] = mp( depth[id], dist[id] );
    }
    hc = 1; cm[0] = -1;
    hs = 1; sm[0] = 0;
    sort( v1, v1 + h1, cmp2 );
    sort( v2, v2 + h2, cmp3 );
    int lst = -1, hh = 0;
    for ( int i = 0; i < h2; i++ )
    {
        if ( v2[i].second != lst ) cm[ hc++ ] = v2[i].second, sm[ hs++ ] = 0, hh++;
        lst = v2[i].second;
        v2[i].second = hh;
    }
    sort( v2, v2 + h2, cmp1 );
    int pnt = 0;
    for ( int i = 0; i < h1; i++ )
    {
        int ll = v1[i].first;
        int ww = v1[i].second;
        while ( true )
        {
            if ( pnt == h2 ) break;
            if ( ll + v2[pnt].first > L ) break;
            modify( v2[pnt++].second );
        }
        if ( cm[0] + ww > W ) continue;
        int l = 1, r = hc - 1, id = 0;
        while ( l <= r )
        {
            int x = ( l + r ) / 2;
            if ( cm[x] + ww <= W )
            {
                id = max( id, x );
                l = x + 1;
            } else r = x - 1;
        }
        answer += fsum( id );
    }
    for ( int i = 0; i < s[b].size(); i++ ) s[a].pb( s[b][i] );
    s[b].clear();
}

void dfs( int v )
{
    subtree[ st++ ] = v;
    bad[v] = true;
    f[v] = 1;
    g[v] = 0;
    for ( int i = 0; i < graf[v].size(); i++ )
    {
        int next = graf[v][i].first;
        if ( bad[ next ] ) continue;
        dfs( next );
        f[v] += f[next];
        g[v] = max( g[v], f[next] );
    }
    bad[v] = false;
}

void dfs1( int v )
{
    bad[v] = true;
    subtree[ st++ ] = v;
    for ( int i = 0; i < graf[v].size(); i++ )
    {
        int next = graf[v][i].first;
        int cost = graf[v][i].second;
        if ( bad[next] ) continue;
        depth[next] = depth[v] + 1;
        dist[next] = dist[v] + cost;
        dfs1( next );
    }
    bad[v] = false;
}

void solve( int v )
{
    while ( cur.size() > 0 ) cur.pop();
    cur.push( v );
    depth[v] = dist[v] = 0;
    s[v].clear();
    s[v].pb( v );
    for ( int i = 0; i < graf[v].size(); i++ )
    {
        int next = graf[v][i].first;
        int cost = graf[v][i].second;
        if ( bad[next] ) continue;
        st = 0;
        depth[next] = 1;
        dist[next] = cost;
        dfs1( next );
        s[next].clear();
        for ( int j = 0; j < st; j++ )
        {
            int id = subtree[j];
            s[next].pb( id );
        }
        cur.push( next );
    }
    while ( cur.size() > 1 )
    {
        int id1 = cur.top(); cur.pop();
        int id2 = cur.top(); cur.pop();
        unite( id1, id2 );
        cur.push( id1 );
    }
}

void fun( int v )
{
    st = 0;
    dfs( v );
    int id = -1;
    for ( int i = 0; i < st; i++ )
    {
        int ii = subtree[i];
        g[ii] = max( g[ii], st - f[ii] );
        if ( id == -1 ) id = ii;
        if ( g[id] > g[ii] ) id = ii;
    }
    bad[id] = true;
    for ( int i = 0; i < graf[id].size(); i++ )
    {
        int next = graf[id][i].first;
        if ( bad[next] ) continue;
        fun( next );
    }
    solve( id );
    bad[id] = false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> L >> W;
    for ( int i = 1; i < n; i++ )
    {
        int p, w; scanf("%d%d", &p, &w);
        graf[p].pb( mp( i + 1, w ) );
        graf[i + 1].pb( mp( p, w ) );
    }
    fun( 1 );
    cout << answer << endl;
    return 0;
}