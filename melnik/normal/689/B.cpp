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

int dist[maxn];
queue < int > forBfs;
vector < int > edge[maxn];

void bfs() {
	forBfs.push( 0 );
	while ( !forBfs.empty() ) {
		int v = forBfs.front();
		forBfs.pop();
		int sz = edge[v].size();
		for ( int j = 0; j < sz; j++ ) {
			int to = edge[v][j];
			if ( dist[to] == inf ) {
				dist[to] = dist[v] + 1;
				forBfs.push( to );
			}
		}
	}
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    for ( int j = 0; j < maxn; j++ )
    	dist[j] = inf;
   	dist[0] = 0;
   	int n;
   	scanf ( "%d", &n );
   	for ( int j = 1; j < n; j++ ) {
   		edge[j].pb( j - 1 );
   		edge[j - 1].pb( j );
   	}
   	for ( int j = 0; j < n; j++ ) {
   		int x;
   		scanf ( "%d", &x );
   		edge[j].pb( --x );
   	}
   	bfs();
   	for ( int j = 0; j < n; j++ )
   		printf ( "%d ", dist[j] );
    return 0;
}