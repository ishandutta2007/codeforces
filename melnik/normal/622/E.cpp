#include <iostream>
#include <fstream>
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

const int maxn = 500500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

vector < int > edge[maxn];
vector < int > H[maxn];
bool used[maxn] = { false };

void dfs( int v, int id, int lvl ) {
    used[v] = true;
    int sz = edge[v].size();
    if ( sz == 1 ) {
        H[id].pb( lvl );
        return;
    }
    for ( int j = 0; j < sz; j++ )
        if ( !used[edge[v][j]] )
            dfs( edge[v][j], id, lvl + 1 );
}

int calc( int id ) {
    sort( H[id].begin(), H[id].end() );
    int cnt = H[id].front();
    int sz = H[id].size();
    for ( int j = 0; j < sz; j++ ) {
        cnt = max( cnt, H[id][j] );
        ++cnt;
    }
    return --cnt;
}

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n, j, x, y;
    scanf ( "%d", &n );
    for ( j = 1; j < n; j++ ) {
        scanf ( "%d%d", &x, &y );
        x--;
        y--;
        edge[x].pb( y );
        edge[y].pb( x );
    }
    int sz = edge[0].size();
    used[0] = true;
    int ans = 0;
//    printf ( "%d\n", sz );
    for ( j = 0; j < sz; j++ ) {
        dfs( edge[0][j], edge[0][j], 1 );
        ans = max( ans, calc( edge[0][j] ) );
    }
    printf ( "%d", ans );
    return 0;
}