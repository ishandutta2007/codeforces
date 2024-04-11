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

bool used[10];
int cnt1 = 1;
int cnt2 = 1;

bool correct( int a, int b ) {
	for ( int j = 0; j < 10; j++ )
		used[j] = false;
	int cur = 7;
	for ( int j = 0; j < cnt1; j++ ) {
		int c = a % cur;
		if ( used[c] )
			return 0;
		used[c] = true;
		a /= cur;
	}
	cur = 7;
	for ( int j = 0; j < cnt2; j++ ) {
		int c = b % cur;
		if ( used[c] )
			return 0;
		used[c] = true;
		b /= cur;
	}
	return 1;
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, m;
    scanf ( "%d%d", &n, &m );
    ll cur1 = 7LL;
    while ( 1LL * n > cur1 ) {
    	++cnt1;
    	cur1 *= 7LL;
    }
    ll cur2 = 7LL;
    while ( 1LL * m > cur2 ) {
    	++cnt2;
    	cur2 *= 7LL;
    }
    if ( cnt1 + cnt2 > 7 ) {
    	printf ( "0\n" );
    	return 0;
    }
    int ans = 0;
    for ( int j = 0; j < n; j++ )
    	for ( int i = 0; i < m; i++ )
    		if ( correct( j, i ) )
    			++ans;
    printf ( "%d\n", ans );
    return 0;
}