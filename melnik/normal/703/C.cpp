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

pair < int, int > a[maxn];

int main()
{
    srand( time( 0 ) );
//     freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, w, v, u;
    scanf ( "%d%d%d%d", &n, &w, &v, &u );
    for ( int j = 0; j < n; j++ )
    	scanf ( "%d%d", &a[j].f, &a[j].s );
    if ( n <= 2 ) {
    	cout << fixed << setprecision( 20 ) << 1.0 * w / u << endl;
    	return 0;
    }
    sort( a, a + n );
    // int dx = a[1].f - a[0].f;
    // int dy =
   	bool correct = true;
   	for ( int j = 0; j < n; j++ )
   		if ( a[j].f < 0 )
   			correct = false;
   	for ( int j = 0; j < n; j++ ) {
   		if ( a[j].f < 0 )
   			continue;
   		if ( 1LL * a[j].f * u < 1LL * a[j].s * v )
   			correct = false;
   	}
//   	cout << correct << endl;
   	if ( correct ) {
   		cout << fixed << setprecision( 20 ) << 1.0 * w / u << endl;
    	return 0;
   	}
   	double ans = 1.0 * w / u;
   	for ( int j = 0; j < n; j++ ) {
   		if ( a[j].f < 0 )
   			continue;
//   		if ( j != n - 1 && 1LL * a[j].f * u >= 1LL * a[j].s * v )
//   			continue;
   		ans = max( ans, 1.0 * a[j].f / v + 1.0 * ( w - a[j].s ) / u );
   	}
   	cout << fixed << setprecision( 20 ) << ans;
    return 0;
}