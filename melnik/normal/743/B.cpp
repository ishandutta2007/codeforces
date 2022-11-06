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

void calc( int cur, ll l, ll r, ll pos ) {
	if ( l == r ) {
		puts( "1" );
		exit( 0 );
	}
	ll mid = ( l + r ) / 2LL;
	if ( pos == mid ) {
		printf ( "%d\n", cur );
		exit( 0 );
	}
	if ( pos < mid )
		calc( cur - 1, l, mid - 1LL, pos );
	else
		calc( cur - 1, mid + 1LL, r, pos );
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
   	int n;
   	ll k;
   	cin >> n >> k;
   	calc( n, 1, ( 1LL ) << n, k );
   	// cout << ( 1LL << n ) << endl;
    return 0;
}