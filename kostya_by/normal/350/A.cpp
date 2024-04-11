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

int n, m, a[ 111 ], b[ 111 ];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    for ( int i = 1; i <= n; i++ ) cin >> a[i];
    for ( int i = 1; i <= m; i++ ) cin >> b[i];
    sort( a + 1, a + n + 1 );
	sort( b + 1, b + m + 1 );
	if ( a[n] >= b[1] )
	{
		cout << -1;
		return 0;
	}
	int ans = max( 2 * a[1], a[n] );
	if ( ans >= b[1] ) ans = -1;
	cout << ans << endl;
    return 0;
}