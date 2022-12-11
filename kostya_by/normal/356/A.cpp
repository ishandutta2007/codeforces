#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <bitset>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, m, ans[ 300300 ];
set< int > s;

void solve( int l, int r, int x )
{
	vector< int > cur;
	while ( true )
	{
		set< int >::iterator it = s.lower_bound( l );
		if ( *it > r ) break;
		cur.pb( *it );
		s.erase( it );
	}
	s.insert( x );
	for ( int i = 0; i < cur.size(); i++ ) ans[ cur[i] ] = x;
	ans[x] = 0;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &m);
    for ( int i = 1; i <= n + 1; i++ ) s.insert( i );
    while ( m-- )
    {
    	int l, r, x; scanf("%d%d%d", &l, &r, &x);
    	solve( l, r, x );
    }
    for ( int i = 1; i <= n; i++ ) printf("%d ", ans[i]);
    return 0;
}