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

char t[maxn];

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d\n", &n );
    gets( t );
    int ans = 1;
    pair < int, int > cur = mp( -1, -1 );
    for ( int j = 0; j < n; j++ ) {
    	if ( t[j] == cur.f )
    		continue;
    	if ( t[j] == cur.s )
    		continue;

    	if ( t[j] == 'L' && ( cur.f == 'R' || cur.s == 'R' ) ) {
    		++ans;
    		cur = mp( t[j], -1 );
    		continue;
    	}
    	if ( t[j] == 'R' && ( cur.f == 'L' || cur.s == 'L' ) ) {
    		++ans;
    		cur = mp( t[j], -1 );
    		continue;
    	}
    	if ( t[j] == 'U' && ( cur.f == 'D' || cur.s == 'D' ) ) {
    		++ans;
    		cur = mp( t[j], -1 );
    		continue;
    	}

    	if ( t[j] == 'D' && ( cur.f == 'U' || cur.s == 'U' ) ) {
    		++ans;
    		cur = mp( t[j], -1 );
    		continue;
    	}

    	if ( cur.f == -1 ) {
    		cur.f = t[j];
    		continue;
    	}
    	if ( cur.s == -1 ) {
    		cur.s = t[j];
    		continue;
    	}
    	++ans;
    	cur = mp( t[j], -1 );
    }
    printf ( "%d\n", ans );
    return 0;
}