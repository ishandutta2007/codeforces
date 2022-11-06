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

const int maxn = 10;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

char t[maxn][maxn];

bool correct( int x, int y ) {
	if ( x >= 4 || y >= 4 )
		return false;
	if ( x < 0 || y < 0 )
		return false; 
	return t[x][y] == 'x';
}

bool good() {
	for ( int j = 0; j < 4; j++ )
		for ( int i = 0; i < 4; i++ ) {
			int x = j, y = i;
			int sum = 0;
			sum += correct( x, y );
			sum += correct( x, y + 1 );
			sum += correct( x, y + 2 );
			if ( sum == 3 ) 
				return true;

			sum = 0;
			sum += correct( x, y );
			sum += correct( x + 1, y );
			sum += correct( x + 2, y );
			if ( sum == 3 ) 
				return true;

			sum = 0;
			sum += correct( x, y );
			sum += correct( x + 1, y + 1 );
			sum += correct( x + 2, y + 2 );
			if ( sum == 3 ) 
				return true;

			sum = 0;
			sum += correct( x, y );
			sum += correct( x + 1, y - 1 );
			sum += correct( x + 2, y - 2 );
			if ( sum == 3 ) 
				return true;
		}
	return false;
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    for ( int j = 0; j < 4; j++ )
    	gets( t[j] );
    for ( int j = 0; j < 4; j++ )
    	for ( int i = 0; i < 4; i++ ) 
    		if ( t[j][i] == '.' ) {
    			t[j][i] = 'x';
    			if ( good() ) {
    				puts( "YES" );
    				return 0;
    			}
    			t[j][i] = '.';
    		}
    puts( "NO" );
    return 0;
}