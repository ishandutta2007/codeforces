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

const int maxn = 205;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn];
multiset < int > cur;
multiset < int > outOfSegment;
multiset < int >::iterator it1, it2;

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
    int ans = -inf;
    for ( int j = 0; j < n; j++ ) {
    	outOfSegment.clear();
    	cur.clear();
    	int curSum = 0;
    	for ( int i = 0; i < n; i++ )
    		outOfSegment.insert( -a[i] );
    	for ( int i = j; i < n; i++ ) {
    		outOfSegment.erase( outOfSegment.find( -a[i] ) );
    		cur.insert( a[i] ); 
    		curSum += a[i];
    		int newSum = curSum;
    		it1 = cur.begin();
    		it2 = outOfSegment.begin();
    		int x = k;
    		while ( x-- && it1 != cur.end() &&
    				it2 != outOfSegment.end() && -( *it2 ) > *it1 ) {
    			newSum -= *it1;
    			newSum -= *it2;
    			++it1;
    			++it2;
    		}
    		ans = max( ans, newSum );
    	}
    }
    printf ( "%d\n", ans );
    return 0;
}