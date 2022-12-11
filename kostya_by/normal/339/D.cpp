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

int n, m, q, a[ 150000 ];
int f1[ 600000 ], f2[ 600000 ];

void init( int v, int l, int r )
{
	if ( l == r )
	{
		f1[v] = f2[v] = a[l];
		return;
	}
	int x = (l + r) / 2;
	init( v + v, l, x );
	init( v + v + 1, x + 1, r );
	f1[v] = f2[v + v] ^ f2[v + v + 1];
	f2[v] = f1[v + v] | f1[v + v + 1];
}

void rebuild( int v, int ll, int rr, int pos )
{
	if ( ll == rr )
	{
		f1[v] = f2[v] = a[ll];
		return;
	}
	int xx = (ll + rr) / 2;
	if ( pos <= xx ) rebuild( v + v, ll, xx, pos );
		else rebuild( v + v + 1, xx + 1, rr, pos );
	f1[v] = f2[v + v] ^ f2[v + v + 1];
	f2[v] = f1[v + v] | f1[v + v + 1];
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &q);
    m = 1 << n;
    for ( int i = 1; i <= m; i++ ) scanf("%d", &a[i]);
    init( 1, 1, m );
	while ( q-- )
	{
		int pos, val; scanf("%d%d", &pos, &val);
		a[pos] = val;
		rebuild( 1, 1, m, pos );
		printf("%d\n", ( n % 2 == 1 ? f2[1] : f1[1] ));
	}
    return 0;
}