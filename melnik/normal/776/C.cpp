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
const int inf = 2e8;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn];
map < ll, int > b;

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, k;
    scanf ( "%d%d", &n, &k );
    for ( int j = 0; j < n; j++ )
    	scanf ( "%d", &a[j] );
    ll sum = 0LL;
    ll ans = 0LL;
    ++b[0];
    for ( int j = 0; j < n; j++ ) {
    	ll cnt = 1;
    	sum += 1LL * a[j];
    	while ( abs( cnt ) <= 1LL * inf * inf ) {
    		// if ( cnt < 0 ) {
    		// 	cnt *= 1LL * k;
    		// 	continue;
    		// }
    		ll needSum = sum - cnt;
    		ans += b[needSum];
    		if ( k == 1 )
    			break;
    		if ( k == -1 && cnt == -1 )
    			break;
    		cnt *= 1LL * k;
    	}
    	++b[sum];
    }
    cout << ans << endl;
    return 0;
}