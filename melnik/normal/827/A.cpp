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

const int maxn = 2000500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

set < int > unUsed;
set < int >::iterator it;
int a[maxn];

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int len = 0;
    for ( int j = 1; j < maxn; j++ )
    	unUsed.insert( j );
    for ( int j = 0; j < n; j++ ) {
    	string t;
    	cin >> t;
    	int cnt;
    	cin >> cnt;
    	while ( cnt-- ) {
    		int l;
    		cin >> l;
    		int r = l + t.size() - 1;
    		len = max( len, r );
    		it = unUsed.lower_bound( l );
    		while ( it != unUsed.end() && *it <= r ) {
    			a[*it] = t[*it - l];
    			unUsed.erase( it );
    			it = unUsed.lower_bound( l );
    		}
    	}
    }

    for ( int j = 1; j <= len; j++ )
    	if ( !a[j] )
    		cout << 'a';
    	else
    		cout << (char) a[j];

    return 0;
}