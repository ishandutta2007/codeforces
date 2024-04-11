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

const int maxn = 105;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn][maxn];

int col[maxn];
int row[maxn];

int Try( int x, int n, int m ) {
	row[0] = x;
	int ans = 0;
	for ( int j = 0; j < m; j++ ) {
		col[j] = a[0][j] - row[0];
		ans += col[j];
	}
	for ( int j = 0; j < n; j++ ) {
		row[j] = a[j][0] - col[0];
		ans += row[j];
	}
	for ( int j = 0; j < n; j++ )
		for ( int i = 0; i < m; i++ ) {
			if ( a[j][i] != row[j] + col[i] )
				return inf;
			if ( row[j] < 0 )
				return inf;
			if ( col[i] < 0 )
				return inf;
		}
	return ans;
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, m;
    scanf ( "%d%d", &n, &m );
    for ( int j = 0; j < n; j++ )
    	for ( int i = 0; i < m; i++ )
    		scanf ( "%d", &a[j][i] );
    int ans = inf;
    int cnt = inf;
    for ( int j = 0; j <= a[0][0]; j++ )
    	if ( Try( j, n, m ) < ans ) {
    		ans = Try( j, n, m );
    		cnt = j;
    	}
    if ( ans == inf ) {
    	puts( "-1" );
    	return 0;
    }
    ans = Try( cnt, n, m );
    printf ( "%d\n", ans );
    for ( int j = 0; j < m; j++ )
		while ( col[j]-- )
			printf ( "col %d\n", j + 1 );
	for ( int j = 0; j < n; j++ )
		while ( row[j]-- )
			printf ( "row %d\n", j + 1 );
    return 0;
}