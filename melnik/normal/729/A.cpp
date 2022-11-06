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
vector < char > ans;

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d\n", &n );
    gets( t );
    int l, r;
    l = r = 0;
    while ( l < n ) {
    	if ( l < n - 2 && t[l] == 'o' && t[l + 1] == 'g' && t[l + 2] == 'o' ) {
    		r = l + 3;
    		while ( r < n - 1 && t[r] == 'g' && t[r + 1] == 'o' )
    			r += 2;
    		ans.pb( '*' );
    		ans.pb( '*' );
    		ans.pb( '*' );
    		l = r;
    	}
    	else {
    		ans.pb( t[l] );
    		++l;
    	}
    }
    int sz = ans.size();
    for ( int j = 0; j < sz; j++ )
    	printf ( "%c", ans[j] );
    return 0;
}