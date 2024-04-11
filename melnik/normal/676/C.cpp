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

char t[maxn];

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, k;
    scanf ( "%d%d\n", &n, &k );
    gets( t );
    int l, r;
    l = r = 0;
    int cur = 0;
    int ans = 0;
    while ( l < n ) {
    	r = max( l, r );
    	while ( r < n && cur <= k )
    		if ( t[r++] == 'b' )
    			++cur;
    	if ( cur <= k )
    		ans = max( ans, r - l );
    	ans = max( ans, r - l - 1 );
    	if ( t[l++] == 'b' )
    		--cur;
    }
    l = r = 0;
    cur = 0;
    while ( l < n ) {
    	r = max( l, r );
    	while ( r < n && cur <= k )
    		if ( t[r++] == 'a' )
    			++cur;
    	if ( cur <= k )
    		ans = max( ans, r - l );
    	ans = max( ans, r - l - 1 );
    	if ( t[l++] == 'a' )
    		--cur;
    }
    printf ( "%d\n", ans );
    return 0;
}