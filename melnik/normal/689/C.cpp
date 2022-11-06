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

ll calc( ll n ) {
	ll ans = 0LL;
	for ( int j = 2; 1LL * j * j * j <= n; j++ )
		ans += 1LL * n / ( 1LL * j * j * j );
	return ans;
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    ll m;
    cin >> m;
    ll l, r;
    l = 1LL;
    r = 1LL * inf * inf / 400LL;
    while ( r - l ) {
    	ll mid = ( l + r ) / 2LL;
    	if ( calc( mid ) < m )
    		l = mid + 1LL;
    	else
    		r = mid;
    }
    if ( calc( l ) == m )
    	cout << l << endl;
    else
    	cout << -1 << endl;
    return 0;
}