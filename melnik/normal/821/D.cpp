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

const int maxn = 10050;
const int inf = 32500;
const double eps = 1e-8;
const int base = 1073676287;

vector < pair < int, int > > a;
short int edge[maxn][maxn];
vector < int > onHor[maxn];
vector < int > onVer[maxn];
int dist[maxn];
list < int > forB;

void bfs( int startId, int k ) {
	for ( int j = 0; j < maxn; j++ )
		dist[j] = inf;
	dist[startId] = 0;
	forB.pb( startId );
	while ( !forB.empty() ) {
		int v = forB.front();
		int len;
		forB.pop_front();
		for ( int j = 0; j < k; j++ ) {
			len = edge[v][j];
			if ( len == inf )
				continue;
			if ( dist[j] > dist[v] + len ) {
				if ( len )
					forB.pb( j );
				else
					forB.push_front( j );
				dist[j] = dist[v] + len;
			}
		}
	}
}

int main()
{
	for ( int j = 0; j < maxn; j++ )
		for ( int i = 0; i < maxn; i++ )
			edge[j][i] = inf;
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, m, k;
    scanf ( "%d%d%d", &n, &m, &k );
    for ( int j = 0; j < k; j++ ) {
    	int x, y;
    	scanf ( "%d%d", &x, &y );
    	a.pb( mp( x, y ) );
    	onHor[x].pb( j );
    	onVer[y].pb( j );
    }
    // for ( int j = 1; j <= n; j++ )
    // 	sort( onHor[j].begin(), onHor[j].end() );
    // for ( int j = 1; j <= m; j++ )
    // 	sort( onVer[j].begin(), onVer[j].end() );

    int id1, id2, Y1, y2, x1, x2;


    for ( int j = 0; j < k; j++ ) {
    	int x = a[j].f;
    	int y = a[j].s;


    	int sz = onHor[x - 1].size();
    	for ( int i = 0; i < sz; i++ ) {
    		edge[j][onHor[x - 1][i]] = 1;
    		edge[onHor[x - 1][i]][j] = 1;
    	}
    	sz = onHor[x + 1].size();
    	for ( int i = 0; i < sz; i++ ) {
    		edge[j][onHor[x + 1][i]] = 1;
    		edge[onHor[x + 1][i]][j] = 1;
    	}

    	sz = onVer[y + 1].size();
    	for ( int i = 0; i < sz; i++ ) {
    		edge[j][onVer[y + 1][i]] = 1;
    		edge[onVer[y + 1][i]][j] = 1;
    	}
    	sz = onVer[y - 1].size();
    	for ( int i = 0; i < sz; i++ ) {
    		edge[j][onVer[y - 1][i]] = 1;
    		edge[onVer[y - 1][i]][j] = 1;
    	}


        if ( x - 2 >= 0 ) {
            sz = onHor[x - 2].size();
            for ( int i = 0; i < sz; i++ ) {
                edge[j][onHor[x - 2][i]] = 1;
                edge[onHor[x - 2][i]][j] = 1;
            }
        }
        sz = onHor[x + 2].size();
        for ( int i = 0; i < sz; i++ ) {
            edge[j][onHor[x + 2][i]] = 1;
            edge[onHor[x + 2][i]][j] = 1;
        }

        sz = onVer[y + 2].size();
        for ( int i = 0; i < sz; i++ ) {
            edge[j][onVer[y + 2][i]] = 1;
            edge[onVer[y + 2][i]][j] = 1;
        }
        if ( y - 2 >= 0 ) {
            sz = onVer[y - 2].size();
            for ( int i = 0; i < sz; i++ ) {
                edge[j][onVer[y - 2][i]] = 1;
                edge[onVer[y - 2][i]][j] = 1;
            }
        }
    }


    for ( int j = 1; j <= n; j++ ) {
    	int sz = onHor[j].size();
    	for ( int i = 0; i < sz; i++ )
    		for ( int y = i + 1; y < sz; y++ ) {
    			id1 = onHor[j][i];
    			id2 = onHor[j][y];
    			Y1 = a[id1].s;
    			y2 = a[id2].s;
    			if ( abs( Y1 - y2 ) == 1 ) {
    				edge[id1][id2] = 0;
    				edge[id2][id1] = 0;
    			} else {
    				edge[id1][id2] = 1;
    				edge[id2][id1] = 1;
    			}
    		}
    }


    for ( int j = 1; j <= m; j++ ) {
    	int sz = onVer[j].size();
    	for ( int i = 0; i < sz; i++ )
    		for ( int y = i + 1; y < sz; y++ ) {
    			id1 = onVer[j][i];
    			id2 = onVer[j][y];
    			x1 = a[id1].f;
    			x2 = a[id2].f;
    			if ( abs( x1 - x2 ) == 1 ) {
    				edge[id1][id2] = 0;
    				edge[id2][id1] = 0;
    			} else {
    				edge[id1][id2] = 1;
    				edge[id2][id1] = 1;
    			}
    		}
    }

    int startId;
    for ( int j = 0; j < k; j++ )
    	if ( a[j] == mp( 1, 1 ) )
    		startId = j;

    bfs( startId, k );

    // for ( int j = 0; j < k; j++ )
    // 	printf( "%d\n", dist[j] );

    int ans = inf;
    for ( int j = 0; j < k; j++ ) {
    	int x = a[j].f;
    	int y = a[j].s;
    	if ( x == n && y == m ) {
    		ans = min( ans, dist[j] );
    		continue;
    	}
    	if ( x == n || y == m ) {
    		ans = min( ans, 1 + dist[j] );
    		continue;
    	}
    	if ( x == n - 1 || y == m - 1 ) {
    		ans = min( ans, 1 + dist[j] );
    		continue;
    	}
    }
    if ( ans == inf )
    	puts( "-1" );
    else
    	printf( "%d\n", ans );
    return 0;
}