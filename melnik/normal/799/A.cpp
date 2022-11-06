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
const int inf = 1e9;
const double eps = 1e-8;
const int base = 1073676287;

bool correct( int x, int n, int t, int k, int d ) {
	ll c1 = 1LL * ( x / t ) * k;
    ll c2 = 1LL * ( max( 0, ( x - d ) ) / t ) * k;
	return n <= c1 + c2;
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, t, k, d;
    scanf ( "%d%d%d%d", &n, &t, &k, &d );
    int t1 = ( n + k - 1 ) / k * t;
    int l = 0;
    int r = inf;
    while ( r - l ) {
    	int mid = ( l + r ) >> 1;
    	if ( !correct( mid, n, t, k, d ) )
    		l = mid + 1;
    	else
    		r = mid;
    }
    if ( t1 != l )
    	puts( "YES" );
    else
    	puts( "NO" );
    return 0;
}