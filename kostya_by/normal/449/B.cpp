#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <stack>
#include <bitset>
#include <sstream>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, m, k, answer = 0;
vector< pair< int, int > > graph[ 100100 ];
long long dist[ 100100 ], init[ 100100 ];
set< pair< long long, int > > s;
bool upd[ 100100 ];

int main (int argc, const char * argv[])
{
    scanf("%d%d%d", &n, &m, &k);
    for ( int i = 0; i < m; i++ )
    {
    	int a, b, c; scanf("%d%d%d", &a, &b, &c);
    	graph[ a ].pb( mp( b, c ) );
    	graph[ b ].pb( mp( a, c ) );
    }

    for ( int i = 1; i <= n; i++ ) init[i] = inf;

    init[1] = 0;

    for ( int i = 0; i < k; i++ )
    {
    	int a, b; scanf("%d%d", &a, &b);
    	if ( init[ a ] != inf ) answer++;
    	init[ a ] = min( init[ a ], (long long)b );
    }

    for ( int i = 1; i <= n; i++ )
    {
    	dist[i] = init[i];
    	s.insert( mp( dist[i], i ) );
    }

    while ( s.size() != 0 )
    {
    	pair< long long, int > cur = *s.begin();
    	s.erase( cur );
    	long long d = cur.first;
    	int v = cur.second;
    	//cout << v << " " << dist[v] << " " << upd[v] << "\n";
    	if ( upd[v] == true ) answer++;

    	for ( int i = 0; i < graph[v].size(); i++ )
    	{
    		int next = graph[v][i].first;
    		int cost = graph[v][i].second;
    		if ( dist[v] + cost <= dist[next] )
    		{
    			s.erase( mp( dist[next], next ) );
    			dist[next] = dist[v] + cost;
    			upd[ next ] = ( init[ next ] != inf );
    			s.insert( mp( dist[next], next ) );
    		}
    	}
    }

    cout << answer << "\n";

    return 0;
}