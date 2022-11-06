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

const int maxn = 105;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

vector < int > edge[maxn];
int used[maxn];
int sz;

void dfs( int v ) {
    used[v] = true;
    ++sz;
    for ( int to : edge[v] ) {
        if ( used[to] )
            continue;
        dfs( to );
    }
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, m;
    scanf ( "%d%d", &n, &m );
    for ( int j = 0; j < m; j++ ) {
        int u, v;
        scanf ( "%d%d", &u, &v );
        edge[u].pb( v );
        edge[v].pb( u );
    }
    ll ans = 1LL;
    for ( int j = 1; j <= n; j++ )
        if ( !used[j] ) {
            dfs( j );
            while ( --sz )
                ans *= 2LL;
        }
    cout << ans << endl;
    return 0;
}