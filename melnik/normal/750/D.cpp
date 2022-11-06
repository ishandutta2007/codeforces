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

const int maxn = 330;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

bool dp[30][6][8][maxn][maxn];
int a[maxn];
pair < int, int > newDir[maxn];
pair < int, int > goTo[maxn];

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d", &n );
    for ( int j = 0; j < n; j++ )
    	scanf ( "%d", &a[j] );
    dp[0][a[0]][0][160][160] = true;
    for ( int j = 0; j < 8; j++ ) {
    	newDir[j].f = ( j + 1 ) % 8;
    	newDir[j].s = j - 1;
    	if ( newDir[j].s < 0 )
    		newDir[j].s += 8;
    }
    goTo[0] = mp( 0, 1 );
    goTo[1] = mp( 1, 1 );
    goTo[2] = mp( 1, 0 );
    goTo[3] = mp( 1, -1 );
    goTo[4] = mp( 0, -1 );
    goTo[5] = mp( -1, -1 );
    goTo[6] = mp( -1, 0 );
    goTo[7] = mp( -1, 1 );


    for ( int j = 0; j < n; j++ )
    	for ( int i = a[j]; i >= 1; i-- )
    		for ( int dir = 0; dir < 8; dir++ )
    			for ( int x = 1; x < 325; x++ )
    				for ( int y = 1; y < 325; y++ ) {
    					if ( !dp[j][i][dir][x][y] )
    						continue;
    					if ( i == 1 && j != n - 1 ) {
    						dp[j + 1][a[j + 1]][newDir[dir].f][x +
    							goTo[newDir[dir].f].f][y +
    							goTo[newDir[dir].f].s] = true;
    						dp[j + 1][a[j + 1]][newDir[dir].s][x +
    							goTo[newDir[dir].s].f][y +
    							goTo[newDir[dir].s].s] = true;
    					}
    					if ( i != 1 ) 
    						dp[j][i - 1][dir][x + goTo[dir].f][y + goTo[dir].s] = true;
    				}
    int ans = 0;
    for ( int x = 0; x < maxn; x++ )
    	for ( int y = 0; y < maxn; y++ ) {
    		bool good = false;
    		for ( int j = 0; j < n; j++ )
    			for ( int i = a[j]; i >= 1; i-- )
    				for ( int dir = 0; dir < 8; dir++ )
    					if ( dp[j][i][dir][x][y] )
    						good = true;
    		ans += (int) good;
    	}
    printf ( "%d\n", ans );
    return 0;
}