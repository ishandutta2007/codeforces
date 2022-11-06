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
    int n, a, b, k;
    scanf ( "%d%d%d%d\n", &n, &a, &b, &k );
    gets( t );
    int l, r;
    l = r = 0;
    int cur = 0;
    while ( l < n ) {
    	if ( t[l] == '1' ) {
    		++l;
    		continue;
    	}
    	r = l;
    	while ( r < n && t[r] == '0' )
    		++r;
    	int len = r - l;
    	cur += len / b;
    	l = r;
    }
   	printf ( "%d\n", cur - a + 1 );
   	l = r = 0;
   	while ( l < n && cur - a + 1 ) {
    	if ( t[l] == '1' ) {
    		++l;
    		continue;
    	}
    	r = l;
    	while ( r < n && cur - a + 1 && t[r] == '0' ) {
    		++r;
    		int len = r - l;
    		if ( len == b ) {
    			--cur;
    			l = r;
    			printf ( "%d ", r );
    		}
    	}
    	l = r;
    }
    return 0;
}