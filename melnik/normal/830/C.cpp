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

ll ans = 1LL;
int a[maxn];
ll RemainderSum;
ll KSum;

set < int > divisors;

inline ll calc( int n, ll x, ll k ) {
	ll sum = 0LL;
	for ( int j = 0; j < n; j++ ) {
		if ( a[j] % x == 0 )
			continue;
		sum += x - 1LL * ( a[j] % x );
		if ( sum > k )
			return sum;
	}
	return sum;
}

inline bool IsTheSame( int n, ll x, ll y ) {
	for ( int j = 0; j < n; j++ )
		if ( a[j] / x != a[j] / y )
			return false;
	return true;
}

inline bool IsDivisor( int n, ll x ) {
	return divisors.find( x ) != divisors.end();
}

inline void calcRemainder( int n, ll d ) {
	RemainderSum = KSum = 0LL;
	for ( int j = 0; j < n; j++ ) {
		RemainderSum += 1LL * ( a[j] % d );
		KSum += 1LL * ( a[j] / d );
	}
	
}

inline ll calcForBin( int n, ll d, ll delta ) {
	return 1LL * n * d - RemainderSum + 1LL * delta * KSum;
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
	for ( int j = 0; j < n; j++ )
		cin >> a[j];

    // n = 100;
    // k = 100LL * inf;
    // for ( int j = 0; j < n; j++ )
        // a[j] = 100LL * inf - ( rand() << 15 ) - rand();
    for ( int j = 0; j < n; j++ ) {
    	for ( int i = 2; i * i <= a[j]; i++ )
    		if ( a[j] % i == 0 ) {
    			divisors.insert( i );
    			divisors.insert( a[j] / i );
    			ll newAns = calc( n, i, k );
    			if ( newAns <= k )
    				ans = max( ans, 1LL * i );
                newAns = calc( n, a[j] / i, k );
    			if ( newAns <= k )
    				ans = max( ans, 1LL * ( a[j] / i ) );
    		}
        ll newAns = calc( n, a[j], k );
        if ( newAns <= k )
            ans = max( ans, 1LL * a[j] );
    }

    for ( int j = 2; j <= 700000; j++ ) {
    	ll newAns = calc( n, j, k );
        if ( newAns <= k )
            ans = max( ans, 1LL * j );
    }

    ll rightBorder = 101LL * inf;
    while ( rightBorder >= 700000 ) {
    	ll l = 1;
    	ll r = rightBorder;
    	while ( r - l ) {
    		ll mid = ( l + r ) / 2LL;
    		if ( IsTheSame( n, mid, rightBorder ) )
    			r = mid;
    		else
    			l = mid + 1LL;
    	}
    	ll leftBorder = l;
    	while ( IsDivisor( n, leftBorder ) )
    		++leftBorder;


    	l = leftBorder;
    	// r = rightBorder;
    	// while ( r - l > 1LL ) {
    	// 	ll mid = ( l + r ) / 2LL;
    	// 	if ( calcForBin( n, mid ) <= calcForBin( n, mid + 1 ) )
    	// 		r = mid;
    	// 	else
    	// 		l = mid;
    	// }

//    	if ( l != leftBorder && l != rightBorder && r != leftBorder && r != rightBorder )
//    		return 228;

    	// if ( calcForBin( n, r ) <= k )
    	// 	l = r;


    	r = rightBorder;
    	calcRemainder( n, leftBorder );


    	while ( r - l > 1LL ) {
    		ll mid = ( l + r ) / 2LL;
    		if ( calcForBin( n, mid, mid - leftBorder ) <= k )
    			l = mid;
    		else
    			r = mid;
    	}
    	if ( calcForBin( n, r, r - leftBorder ) <= k )
    		l = r;


        if ( calcForBin( n, l, l - leftBorder ) <= k )
            ans = max( ans, l );


    	--leftBorder;
    	while ( leftBorder >= 700000 && IsDivisor( n, leftBorder ) )
    		--leftBorder;
    	rightBorder = leftBorder;
    }
    cout << ans << endl;
    return 0;
}