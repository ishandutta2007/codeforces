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

vector < pair < int, int > > edge[maxn];
ll dist[maxn];
set < pair < ll, int > > forD;

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, m, k;
    scanf ( "%d%d%d", &n, &m, &k );
    for ( int j = 0; j < m; j++ ) {
    	int u, v, l;
    	scanf ( "%d%d%d", &u, &v, &l );
    	edge[u].pb( mp( v, l ) );
    	edge[v].pb( mp( u, l ) );
    }
    for ( int j = 0; j < maxn; j++ )
    	dist[j] = 1LL * inf * inf;
    for ( int j = 0; j < k; j++ ) {
    	int v;
    	scanf ( "%d", &v );
    	dist[v] = 0LL;
    	forD.insert( mp( 0, v ) );
    }
    while ( !forD.empty() ) {
    	int v = forD.begin() -> s;
    	forD.erase( forD.begin() );
    	int sz = edge[v].size();
    	for ( int j = 0; j < sz; j++ ) {
    		int to = edge[v][j].f;
    		int len = edge[v][j].s;
    		if ( dist[to] > dist[v] + 1LL * len ) {
    			forD.erase( mp( dist[to], to ) );
    			dist[to] = dist[v] + 1LL * len;
    			forD.insert( mp( dist[to], to ) );
    		}
    	} 
    }
    ll mi = 1LL * inf * inf;
    for ( int j = 1; j <= n; j++ ) {
    	if ( dist[j] == 0LL )
    		continue;
    	mi = min( mi, dist[j] );
    }
    if ( mi == 1LL * inf * inf )
    	printf ( "-1\n" );
    else
    	cout << mi << endl;
    return 0;
}