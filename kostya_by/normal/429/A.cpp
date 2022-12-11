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

int n, value[ 100100 ];
vector< int > graph[ 100100 ];
vector< int > answer;

void solve( int v, int prev, int a, int b )
{
	value[ v ] ^= a;
	if ( value[ v ] )
	{
		answer.push_back( v );
		a ^= 1;
	} 
	for ( int i = 0; i < graph[v].size(); i++ )
	{
		int next = graph[v][i];
		if ( next == prev ) continue;
		solve( next, v, b, a );
	}
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for ( int i = 1; i < n; i++ )
	{
		int u, v; scanf("%d%d", &u, &v);
		graph[u].push_back( v );
		graph[v].push_back( u );
	}
	for ( int i = 1; i <= n; i++ ) scanf("%d", &value[i]);
	for ( int i = 1; i <= n; i++ )
	{
		int x; scanf("%d", &x);
		value[i] ^= x;
	}
	solve( 1, -1, 0, 0 );
	cout << answer.size() << "\n";
	for ( int i = 0; i < answer.size(); i++ ) cout << answer[i] << "\n";
    return 0;
}