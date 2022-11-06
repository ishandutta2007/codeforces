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

bool correct( char x ) {
	if ( x == 'A' )
		return true;
	if ( x == 'E' )
		return true;
	if ( x == 'I' )
		return true;
	if ( x == 'O' )
		return true;
	if ( x == 'U' )
		return true;
	if ( x == 'Y' )
		return true;
	return false;
}

char t[maxn];

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
   	gets( t );
   	int n = strlen( t );
   	int pos = -1;
   	int l, r;
   	l = r = 0;
   	int ans = 0;
   	while ( l < n ) {
   	    r = l;
   		while ( r < n && !correct( t[r] ) )
   			++r;
   		ans = max( ans, r - pos );
   		pos = r;
   		l = r + 1;
   	}
   	printf ( "%d\n", ans );
    return 0;
}