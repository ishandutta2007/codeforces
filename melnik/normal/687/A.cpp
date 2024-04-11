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

vector < int > edge[maxn];
bool used[maxn];
int color[maxn];

void dfs( int v, int col ) {
	used[v] = true;
	color[v] = col;
	int newCol;
	if ( col == 1 )
		newCol = 2;
	else
		newCol = 1;
	int sz = edge[v].size();
	for ( int j = 0; j < sz; j++ ) {
		int to = edge[v][j];
		if ( used[to] ) {
			if ( color[to] == color[v] ) {
				printf ( "-1\n" );
				exit( 0 );
			}
			continue;
		}
		dfs( to, newCol );
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
    	--u;
    	--v;
    	edge[u].pb( v );
    	edge[v].pb( u );
    }
    for ( int j = 0; j < n; j++ ) {
    	if ( !used[j] )
    		dfs( j, 1 );
    }
    int ans = 0;
    for ( int j = 0; j < n; j++ )
    	if ( color[j] == 2 )
    		++ans;
    printf ( "%d\n", ans );
    for ( int j = 0; j < n; j++ )
    	if ( color[j] == 2 )
    		printf( "%d ", j + 1 );
    printf( "\n%d\n", n - ans );
    for ( int j = 0; j < n; j++ )
    	if ( color[j] != 2 )
    		printf( "%d ", j + 1 );
    return 0;
}