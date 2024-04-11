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

vector < int > a[maxn][maxn][12];
int sum[maxn][maxn][12];

inline int getSum( int x1, int y1, int x2, int y2, int c ) {
	return sum[x2][y2][c] - sum[x1 - 1][y2][c] - sum[x2][y1 - 1][c] + sum[x1 - 1][y1 - 1][c];
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, q, c;
    scanf ( "%d%d%d", &n, &q, &c );
    for ( int j = 0; j < n; j++ ) {
    	int x, y, b;
    	scanf ( "%d%d%d", &x, &y, &b );
    	a[x][y][0].pb( b );
    }
    for ( int j = 1; j < 12; j++ ) 
    	for ( int i = 0; i < maxn; i++ )
    		for ( int y = 0; y < maxn; y++ )
    			for ( int x : a[i][y][j - 1] )
    				a[i][y][j].pb( ( x + 1 ) % ( c + 1 ) );
    for ( int j = 0; j < 12; j++ )
    	for ( int i = 1; i < maxn; i++ )
    		for ( int y = 1; y < maxn; y++ ) {
    			sum[i][y][j] = sum[i - 1][y][j] + sum[i][y - 1][j] - sum[i - 1][y - 1][j];
    			for ( int x : a[i][y][j] )
    				sum[i][y][j] += x;
    		}
    while ( q-- ) {
    	int t, x1, y1, x2, y2;
    	scanf ( "%d%d%d%d%d", &t, &x1, &y1, &x2, &y2 );
    	t %= ( c + 1 );
    	printf( "%d\n", getSum( x1, y1, x2, y2, t ) ); 
    }
    return 0;
}