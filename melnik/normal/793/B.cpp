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

const int maxn = 1050;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

char t[maxn][maxn];
int dp[maxn][maxn][4][4];
int n, m;

queue < pair < pair < int, int >, pair < int, int > > > forB;

void Try( int x, int y, int c, int dir, int oldX, int oldY ) {
	if ( x < 0 || x >= n )
		return;
	if ( y < 0 || y >= m )
		return;
	if ( t[x][y] == '*' )
		return;
	if ( dir == 0 && y != oldY + 1 )
		++c;
	if ( dir == 1 && x != oldX + 1 )
		++c;
	if ( dir == 2 && y != oldY - 1 )
		++c;
	if ( dir == 3 && x != oldX - 1 )
		++c;
	int newDir;

	if ( y == oldY + 1 )
		newDir = 0;
	if ( x == oldX + 1 )
		newDir = 1;
	if ( y == oldY - 1 )
		newDir = 2;
	if ( x == oldX - 1 )
		newDir = 3;

	if ( c > 2 )
		return;
	if ( dp[x][y][c][newDir] )
		return;
	dp[x][y][c][newDir] = true;
	forB.push( mp( mp( x, y ), mp( c, newDir ) ) );
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    
    scanf ( "%d%d\n", &n, &m );
    for ( int j = 0; j < n; j++ ) {
    	gets( t[j] );
    	for ( int i = 0; i < m; i++ )
    		if ( t[j][i] == 'S' ) {
    			dp[j][i][0][0] = 1;
    			dp[j][i][0][1] = 1;
    			dp[j][i][0][2] = 1;
    			dp[j][i][0][3] = 1;
    			forB.push( mp( mp( j, i ), mp( 0, 0 ) ) );
    			forB.push( mp( mp( j, i ), mp( 0, 1 ) ) );
    			forB.push( mp( mp( j, i ), mp( 0, 2 ) ) );
    			forB.push( mp( mp( j, i ), mp( 0, 3 ) ) );
    		}
    }
    while ( !forB.empty() ) {
    	pair < pair < int, int >, pair < int, int > > cur = forB.front();
    	forB.pop();
    	int x = cur.f.f;
    	int y = cur.f.s;
    	Try( x + 1, y, cur.s.f, cur.s.s, x, y );
    	Try( x - 1, y, cur.s.f, cur.s.s, x, y );
    	Try( x, y + 1, cur.s.f, cur.s.s, x, y );
    	Try( x, y - 1, cur.s.f, cur.s.s, x, y );
    }
    bool ans = false;
    for ( int j = 0; j < n; j++ )
    	for ( int i = 0; i < m; i++ )
    		if ( t[j][i] == 'T' )
    			for ( int y = 0; y < 4; y++ )
    				ans |= dp[j][i][0][y] | dp[j][i][1][y] | dp[j][i][2][y];
    if ( ans )
    	puts( "YES" );
    else
    	puts( "NO" );
    return 0;
}