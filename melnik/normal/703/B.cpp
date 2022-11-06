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

int c[maxn];

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, k;
    scanf ( "%d%d", &n, &k );
    for ( int j = 0; j < n; j++ )
    	scanf ( "%d", &c[j] );
    ll ans = 0LL;
    for ( int j = 1; j < n; j++ )
    	ans += 1LL * c[j] * c[j - 1];
    ans += 1LL * c[n - 1] * c[0];
    int sum = 0;
    for ( int j = 0; j < n; j++ )
    	sum += c[j];
    for ( int j = 0; j < k; j++ ) {
    	int x;
    	scanf ( "%d", &x );
    	--x;
    	int l = x - 1;
    	int r = x + 1;
    	r %= n;
    	if ( l < 0 )
    		l = n - 1;
    	int curSum = sum - c[l] - c[r] - c[x];
    	ans += 1LL * curSum * c[x];
    	sum -= c[x];
    	c[x] = 0;
    }
    cout << ans << endl;
    return 0;
}