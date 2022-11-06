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

double ans[maxn];
int sz[maxn];
vector < int > edge[maxn];

void dfs( int v ) {
	int SZ = edge[v].size();
	sz[v] = 1;
	for ( int j = 0; j < SZ; j++ ) {
		int to = edge[v][j];
		dfs( to );
		sz[v] += sz[to];
	}
}

void dfs( int v, int anc ) {
	ans[v] = ans[anc] + ( sz[anc] - sz[v] - 1 ) / 2.0 + 1.0;
	int SZ = edge[v].size();
	for ( int j = 0; j < SZ; j++ ) {
		int to = edge[v][j];
		dfs( to, v );
	}
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d", &n );
    for ( int j = 2; j <= n; j++ ) {
    	int v;
    	scanf ( "%d", &v );
    	edge[v].pb( j );
    }
    dfs( 1 );
    sz[0] = n + 1;
    ans[0] = 0;
    dfs( 1, 0 );
    for ( int j = 1; j <= n; j++ )
    	cout << fixed << setprecision( 20 ) << ans[j] << endl;
    return 0;
}