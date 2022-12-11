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

int n, a[ 4444 ], b[ 4444 ], c[ 4444 ];
vector< int > fi, se;
long long s1 = 0, s2 = 0;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for ( int i = 0; i < n + n; i++ )
    {
    	int aa, bb; scanf("%d.%d", &aa, &bb);
    	a[i] = aa * 1000;
    	b[i] = aa * 1000; if ( bb != 0 ) b[i] += 1000;
    	c[i] = aa * 1000 + bb;
    	s1 += a[i];
    	s2 += c[i];
    	if ( a[i] == b[i] ) se.pb( i ); else fi.pb( i );
    }
    long long ans = inf;
    for ( int i = 0; i <= n; i++ )
    {
    	if ( i + se.size() >= n )
    	{
    		long long val = s1 + 1000ll * i - s2;
    		ans = min( ans, max( val, -val ) );
    	}
    }
	cout << ans / 1000 << ".";
    ans %= 1000;
    if ( ans < 100 ) cout << "0";
    if ( ans < 10 ) cout << "0";
    cout << ans << endl;
    return 0;
}