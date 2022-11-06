#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cstdlib>


using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 100500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn];
int h[maxn];
int component[maxn];
bool used[maxn];
int timer;
vector < int > edge[maxn];
bool ifRoot[maxn];

vector < int > ans;
vector < int > curAns;

void init() {
    for ( int j = 0; j < maxn; j++ )
        used[j] = false;
}

void dfs( int v, int curH ) {
    component[v] = timer;
    used[v] = true;
    h[v] = curH;
    int sz = edge[v].size();
    for ( int j = 0; j < sz; j++ ) {
        int to = edge[v][j];
        if ( !used[to] )
            dfs( to, curH + 1 );
    }
}

int dfs2( int v ) {
    used[v] = true;
    int sz = edge[v].size();
    int minH = inf;
    for ( int j = 0; j < sz; j++ ) {
        int to = edge[v][j];
        if ( !used[to] )
            minH = min( minH, dfs2( to ) );
    }
    if ( minH == inf ) {
        ans.pb( a[v] );
        return h[a[v]];
    }
    if ( minH == h[v] ) {
        ans.pb( a[v] );
        return h[a[v]];
    }
    if ( minH < h[a[v]] ) {
        printf ( "-1" );
        exit( 0 );
    }
    if ( minH > h[a[v]] && minH < h[v] ) {
        printf ( "-1" );
        exit( 0 );
    }
    ans.pb( a[v] );
    return min( minH, h[a[v]] );
}

bool correct( int n ) {
    return true;
}


int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    for ( int j = 0; j < maxn; j++ )
        ifRoot[j] = true;
    int n, m;
    scanf ( "%d%d", &n, &m );
    for ( int j = 0; j < m; j++ ) {
        int u, v;
        scanf ( "%d%d", &u, &v );
        --u;
        --v;
        edge[u].pb( v );
        ifRoot[v] = false;
    }
    for ( int j = 0; j < n; j++ ) {
        scanf ( "%d", &a[j] );
        --a[j];
    }
    init();
    for ( int j = 0; j < n; j++ )
        if ( ifRoot[j] ) {
            dfs( j, 0 );
            ++timer;
        }
    for ( int j = 0; j < n; j++ )
        if ( component[j] != component[a[j]] ) {
            printf ( "-1\n" );
            return 0;
        }
    init();
    for ( int j = 0; j < n; j++ )
        if ( ifRoot[j] )
            int x = dfs2( j );
    int sz = ans.size();
    init();
    for ( int j = n - 1; j >= 0; j-- )
        if ( !used[ans[j]] ) {
            curAns.pb( ans[j] );
            used[ans[j]] = true;
        }
    ans = curAns;
    reverse( ans.begin(), ans.end() );
    sz = ans.size();
    printf ( "%d\n", sz );
    for ( int j = 0; j < sz; j++ )
        printf ( "%d\n", ans[j] + 1 );
    return 0;
}