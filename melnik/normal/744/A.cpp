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

int c[maxn];
vector < int > edge[maxn];
int timer;
int used[maxn];
pair < int, int > components[maxn];

void dfs( int v ) {
	used[v] = true;
	++components[timer].f;
	int sz = edge[v].size();
	components[timer].s += sz;
	for ( int j = 0; j < sz; j++ ) {
		int to = edge[v][j];
		if ( !used[to] )
			dfs( to );
	}
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, m, k;
    scanf ( "%d%d%d", &n, &m, &k );
    for ( int j = 0; j < k; j++ )
    	scanf ( "%d", &c[j] );
   	for ( int j = 0; j < m; j++ ) {
   		int u, v;
   		scanf ( "%d%d", &u, &v );
   		edge[u].pb( v );
   		edge[v].pb( u );
   	}
   	for ( int j = 0; j < k; j++ ) {
   		dfs( c[j] );
   		components[timer].s /= 2;
   		++timer;
   	}
   	for ( int j = 1; j <= n; j++ )
   		if ( !used[j] ) {
   			dfs( j );
   			components[timer].s /= 2;
   			++timer;
   		}
   	sort( components, components + k );
//   	reverse( components. components + k );
   	int add = 0;
   	for ( int j = 0; j < timer; j++ )
   		add += ( components[j].f * ( components[j].f - 1 ) ) / 2 - components[j].s;
   	for ( int j = k; j < timer; j++ ) {
   		add += components[j].f * components[k - 1].f;
   		components[k - 1].f += components[j].f;
   	}
   	printf ( "%d\n", add );
    return 0;
}