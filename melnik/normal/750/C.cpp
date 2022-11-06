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

const int maxn = 200500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int c[maxn];
int d[maxn];

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
   	scanf ( "%d", &n );
   	for ( int j = 0; j < n; j++ )
   		scanf ( "%d%d", &c[j], &d[j] );
   	int delta = 0;
   	int curMaxAns = inf;
   	for ( int j = 0; j < n; j++ ) {
   		if ( d[j] == 2 )
   			curMaxAns = min( curMaxAns, 1899 - delta );
   		delta += c[j];
   	}
   	if ( curMaxAns == inf ) {
   		puts( "Infinity" );
   		return 0;
   	}
   	int cur = curMaxAns;
   	for ( int j = 0; j < n; j++ ) {
   		if ( cur < 1900 && d[j] == 1 ) {
   			puts( "Impossible" );
   			return 0;
   		}
   		if ( cur >= 1900 && d[j] == 2 ) {
   			puts( "Impossible" );
   			return 0;
   		}
   		cur += c[j];
    }
    printf ( "%d\n", cur );
    return 0;
}