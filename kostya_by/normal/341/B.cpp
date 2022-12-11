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

int n, ans = 0, fw[ 100100 ];

int fmax( int pos )
{
	int res = 0;
	while ( pos > 0 )
	{
		res = max( res, fw[pos] );
		pos = pos & (pos - 1);
	}
	return res;
}

void upd( int pos, int val )
{
	while ( pos < 100100 )
	{
		fw[pos] = max( fw[pos], val );
		pos = 2 * pos - ( pos & ( pos - 1 ) );
	}
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ )
    {
    	int a; scanf("%d", &a);
    	int cur = fmax( a ) + 1;
    	ans = max( ans, cur );
    	upd( a, cur );
    }
    cout << ans << endl;
    return 0;
}