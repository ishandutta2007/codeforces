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

const int maxn = 200500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int used[maxn];
int a[maxn];
vector < pair < int, int > > edge[maxn];
multiset < ll > * subTree[maxn];
multiset < ll >::iterator it;
int SZ[maxn];
int ans[maxn];
ll push[maxn];
 
void dfs( int v, int anc ) {
    SZ[v] = 1;
    used[v] = true;
    int maxSon = -1;
    int maxSz = -1;
    int maxLen;
 	int sz = edge[v].size();
    for ( int j = 0; j < sz; j++) {
        int to = edge[v][j].f;
        int len = edge[v][j].s;
        if ( used[to] )
        	continue;
        dfs( to, v );
        SZ[v] += SZ[to];
        if ( SZ[to] > maxSz ) {
        	maxLen = len;
        	maxSon = to;
            maxSz = SZ[to];            
        }        
    }
 
    if ( maxSon == -1 )
        subTree[v] = new multiset < ll >();
    if ( maxSon != -1 ) {
    	push[v] = push[maxSon] + 1LL * maxLen;
        subTree[v] = subTree[maxSon];
    }
 
    for ( int j = 0; j < sz; j++ ) {
        int to = edge[v][j].f;
        int len = edge[v][j].s;
        if ( to == anc )
        	continue;
        if ( to == maxSon )
        	continue;
        for ( it = subTree[to] -> begin(); it != subTree[to] -> end(); it++ )
            subTree[v] -> insert( ( *it ) - 1LL * len - push[to] + push[v] );
    }
    while ( !subTree[v] -> empty() && ( *( subTree[v] -> begin() ) ) < push[v] )
        subTree[v] -> erase( subTree[v] -> begin() );
    ans[v] = subTree[v] -> size();
    subTree[v] -> insert( push[v] + 1LL * a[v] );
}


int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d", &n );
    for ( int j = 1; j <= n; j++ ) {
        scanf ( "%d", &a[j] );
        push[j] = 0LL;
    }
    for ( int j = 2; j <= n; j++ ) {
 		int anc, w;
 		scanf ( "%d%d", &anc, &w );
        edge[j].pb( mp( anc, w ) );
        edge[anc].pb( mp( j, w ) );
    }
    dfs( 1, -1 );
    for ( int j = 1; j <= n; j++ )
        cout << ans[j] << ' ';
    return 0;
}