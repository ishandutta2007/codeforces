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

const int maxn = 100;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn];
int b[maxn][maxn];
int c[maxn][maxn];

bool correct( int dx, int dy ) {
	for ( int j = 0; j < 5; j++ )
		for ( int i = 0; i < 5; i++ )
			if ( b[j][i] && !c[j + dx][i + dy] )
				return 0;
	return 1;
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    for ( int j = 5; j < 8; j++ )
    	for ( int i = 5; i < 8; i++ )
    		c[j][i] = 1;
    c[8][6] = 1;
    int n;
    scanf ( "%d\n", &n );
    for ( int j = 0; j < n; j++ ) {
    	char t;
    	scanf ( "%c", &t );
    	a[j] = t - '0';
    	if ( !a[j] )
    		b[3][1] = 1;
    	else {
    		int x = ( a[j] - 1 ) / 3;
    		int y = ( a[j] - 1 ) % 3 ;
    		b[x][y] = 1; 
    	}
    }
    int ans = 0;
    for ( int dx = 0; dx < 15; dx++ )
    	for ( int dy = 0; dy < 15; dy++ ) 
    		ans += correct( dx, dy );
   	if ( ans != 1 )
   		puts( "NO" );
   	else
   		puts( "YES" );
    return 0;
}