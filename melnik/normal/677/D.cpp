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

int a[305][305];
vector < pair < int, int > > pos[maxn];
int cnt[maxn];
int dist[305][305];
set < pair < int, pair < int, int > > > forD;

void init() {
	for ( int j = 0; j < 305; j++ )
		for ( int i = 0; i < 305; i++ )
			dist[j][i] = inf;
	int sz = cnt[1];
	for ( int j = 0; j < sz; j++ ) {
		int x = pos[1][j].f;
		int y = pos[1][j].s;
		dist[x][y] = x + y;
	}
}

int getDist( int x1, int y1, int x2, int y2 ) {
	return abs( x1 - x2 ) + abs( y1 - y2 );
}

void solve1( int cur, int n, int m ) {
	int sz1 = cnt[cur];
	int sz2 = cnt[cur + 1];
	for ( int j = 0; j < sz1; j++ )
		for ( int i = 0; i < sz2; i++ ) {
			int x1 = pos[cur][j].f;
			int y1 = pos[cur][j].s;
			int x2 = pos[cur + 1][i].f;
			int y2 = pos[cur + 1][i].s;
			dist[x2][y2] = min( dist[x2][y2], getDist( x1, y1, x2, y2 ) + dist[x1][y1] );
		}
}

void Try( int x1, int y1, int x2, int y2, int n, int m ) {
	if ( x2 < 0 || y2 < 0 )
		return;
	if ( x2 >= n || y2 >= m )
		return;
	if ( dist[x2][y2] > dist[x1][y1] + 1 ) {
		forD.erase( mp( dist[x2][y2], mp( x2, y2 ) ) );
		dist[x2][y2] = dist[x1][y1] + 1;
		forD.insert( mp( dist[x2][y2], mp( x2, y2 ) ) );
	}
}

void solve2( int cur, int n, int m ) {
	for ( int j = 0; j < n; j++ )
		for ( int i = 0; i < m; i++ )
			if ( a[j][i] != cur )
				dist[j][i] = inf;
	int sz = cnt[cur];
	for ( int j = 0; j < sz; j++ ) {
		int x = pos[cur][j].f;
		int y = pos[cur][j].s;
		forD.insert( mp( dist[x][y], mp( x, y ) ) );
	}
	while ( !forD.empty() ) {
		pair < int, pair < int, int > > q = *forD.begin();
		forD.erase( forD.begin() );
		int dist = q.f;
		int x = q.s.f;
		int y = q.s.s;
		Try( x, y, x - 1, y, n, m );
		Try( x, y, x + 1, y, n, m );
		Try( x, y, x - 0, y - 1, n, m );
		Try( x, y, x - 0, y + 1, n, m );
	}
	for ( int j = 0; j < n; j++ )
		for ( int i = 0; i < m; i++ )
			if ( a[j][i] != cur + 1 )
				dist[j][i] = inf;
}

void out( int n, int m ) {
	for ( int j = 0; j < n; j++ ) {
		for ( int i = 0; i < m; i++ )
			printf ( "%d ", dist[j][i] );
		printf ( "\n" );
	}
	printf ( "\n" );
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, m, p;
    scanf ( "%d%d%d", &n, &m, &p );
    for ( int j = 0; j < n; j++ )
    	for ( int i = 0; i < m; i++ ) {
    		scanf ( "%d", &a[j][i] );
    		++cnt[a[j][i]];
    		pos[a[j][i]].pb( mp( j, i ) );
    	}
   	init();
   	for ( int cur = 1; cur < p; cur++ ) {
   		if ( cnt[cur] * cnt[cur + 1] < 4000000 )
   			solve1( cur, n, m );
   		else
   			solve2( cur, n, m );
   		// out( n, m );
   	}
   	for ( int j = 0; j < n; j++ )
   		for ( int i = 0; i < m; i++ )
   			if ( a[j][i] == p ) {
   				printf ( "%d\n", dist[j][i] );
   				return 0;
   			}
    return 0;
}