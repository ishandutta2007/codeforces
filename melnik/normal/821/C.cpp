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

char t[10];
set < int > a;
vector < int > b;

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int q;
    scanf ( "%d\n", &q );
    q *= 2;
    int ans = 0;
    int cur = 0;
    while ( q-- ) {
    	char type = getchar();
    	if ( type == 'a' ) {
    		type = getchar();
    		type = getchar();
    		type = getchar();
    		int x;
    		scanf ( "%d\n", &x );
    		b.pb( x );
    		continue;
    	}
    	++cur;
    	gets( t );
    	int sz = b.size();
    	if ( sz ) {
    		if ( b[sz - 1] == cur ) {
    			b.pop_back();
    			continue;
    		}
    		for ( int j = 0; j < sz; j++ )
    			a.insert( b[j] );
    		b.clear();
    		++ans;
    		a.erase( cur );
    		continue;
    	}
    	a.erase( cur );
    }
    printf ( "%d\n", ans );
    return 0;
}