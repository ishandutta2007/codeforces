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
int used[maxn];
int sz[maxn];
int centroid;

void dfs( int v, int anc, int CentroidSize ) {
    sz[v] = 1;
    int MaxSonSize = 0;
    int UpperSize = CentroidSize - 1;
    for ( int to : edge[v] ) {
        if ( used[to] )
            continue;
        if ( to == anc )
            continue;
        dfs( to, v, CentroidSize );
        sz[v] += sz[to];
        MaxSonSize = max( MaxSonSize, sz[to] );
        UpperSize -= sz[to];
    }
    if ( MaxSonSize <= CentroidSize / 2 && UpperSize <= CentroidSize / 2 )
        centroid = v;
}


void BuildCentroid( int v, int num, int CentroidSize ) {
    dfs( v, -1, CentroidSize );
    int CurCentroid = centroid;
    used[CurCentroid] = num;
    for ( int to : edge[CurCentroid] ) {
        if ( used[to] )
            continue;
        if ( sz[to] < sz[CurCentroid] )
            BuildCentroid( to, num + 1, sz[to] );
        else
            BuildCentroid( to, num + 1, CentroidSize - sz[CurCentroid] );
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
    for ( int j = 1; j < n; j++ ) {
        int u, v;
        scanf ( "%d%d", &u, &v );
        edge[u].pb( v );
        edge[v].pb( u );
    }
    BuildCentroid( 1, 1, n );
    for ( int j = 1; j <= n; j++ )
        printf( "%c ", 'A' + used[j] - 1 );
    return 0;
}