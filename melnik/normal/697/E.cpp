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
const int base = 1e9 + 7;

int bin( int curC, ll st ) {
	if ( st == 1LL )
		return curC;
	int newC = bin( curC, st / 2LL );
	newC = ( 1LL * newC * newC ) % base;
	if ( st & 1LL )
		return ( 1LL * curC * newC ) % base;
	return newC;
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d", &n );
    int numerator = 2;
    int denominator = 2;
    bool odd = true;
    while ( n-- ) {
    	ll x;
    	cin >> x;
    	odd = min( 1LL * odd, x % 2LL );
    	denominator = bin( denominator, x );
    }
    numerator = denominator;
    denominator = ( 1LL * denominator * bin( 2, base - 2 ) ) % base;
    if ( odd ) {
    	numerator -= 2;
    	if ( numerator < 0 )
    		numerator += base;
    	numerator = ( 1LL * numerator * bin( 3, base - 2 ) ) % base;
    	numerator = ( 1LL * numerator * bin( 2, base - 2 ) ) % base;
    }
    if ( !odd ) {
    	numerator += 2;
    	numerator %= base;
    	numerator = ( 1LL * numerator * bin( 3, base - 2 ) ) % base;
    	numerator = ( 1LL * numerator * bin( 2, base - 2 ) ) % base;	
    }
    printf ( "%d/%d\n", numerator, denominator );
    return 0;
}