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

int a[maxn];

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
    int cnt = inf;
    for ( int j = 0; j < n; j++ )
    	cnt = min( cnt, a[j] );
    ll ans = 0LL;
    for ( int j = 0; j < n; j++ )
    	if ( ( a[j] - cnt ) % k ) {
    		puts( "-1" );
    		return 0;
    	} else
    		ans += 1LL * ( a[j] - cnt ) / k;
    cout << ans << endl;
    return 0;
}