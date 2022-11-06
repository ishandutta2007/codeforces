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

ll a[maxn];
int b[maxn];
int c[maxn];
int bit[64];
int bits2[64];

void check( int n ) {
    ll sum = 0LL;
	for ( int j = 0; j < n; j++ ) {
	    sum += a[j];
		int x = a[j];
		int pos = 0;
		while ( x ) {
			bit[pos++] += x % 2;
			x /= 2;
		}
	}
	for ( int j = 0; j < n; j++ ) {
		int x = a[j];
		int pos = 0;
		for ( int i = 0; i < 64; i++ )
			bits2[i] = 0;
		while ( x ) {
			bits2[pos++] = x % 2;
			x /= 2;
		}
		ll cnt = 0LL;
		ll deg = 1LL;
		for ( int i = 0; i < 60; i++ ) {
			if ( bits2[i] )
				cnt += 1LL * bit[i] * deg;
			deg *= 2LL;
		}
		if ( cnt != b[j] ) {
			puts( "-1" );
			exit( 0 );
		}
		if ( 1LL * a[j] * n + sum != 1LL * b[j] + 1LL * c[j] ) {
			puts( "-1" );
			exit( 0 );
        }
    }
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    ll sum = 0LL;
    scanf ( "%d", &n );
    for ( int j = 0; j < n; j++ ) {
    	scanf ( "%d", &b[j] );
    	sum += 1LL * b[j];
    }
    for ( int j = 0; j < n; j++ ) {
   		scanf ( "%d", &c[j] );
   		sum += 1LL * c[j];
    }
    if ( sum % ( 2LL * n ) != 0LL ) {
    	puts( "-1" );
    	return 0;
    }
    sum /= 2LL * n;
    for ( int j = 0; j < n; j++ ) {
    	int cur = b[j] + c[j];
    	a[j] = cur - sum;
    	if ( a[j] < 0LL ) {
    		puts( "-1" );
    		return 0;
    	}
    	if ( 1LL * a[j] % n != 0LL ) {
    		puts( "-1" );
    		return 0;
    	}
    	a[j] /= 1LL * n;
    }
    check( n );
    for ( int j = 0; j < n; j++ )
    	cout << a[j] << ' ';
    return 0;
}