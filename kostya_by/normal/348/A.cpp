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
const long long inf = 1e12;

using namespace std;

int n;
long long a[ 100100 ];

bool check( long long x )
{
    long long c = 0;
    for ( int i = 0; i < n; i++ ) c += x - a[i];
    if ( x <= c ) return true;
    return false;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    long long mx = 0;
    for ( int i = 0; i < n; i++ ) 
    {
        int aa; scanf("%d", &aa);
        mx = max( mx, (long long)aa );
        a[i] = aa;
    }
    long long l = mx, r = inf - 1, ans = inf;
    while ( l <= r )
    {
        long long x = (l + r) / 2;
        if ( check( x ) )
        {
            ans = min( ans, x );
            r = x - 1;
        } else l = x + 1;
    }
    cout << ans << endl;
    return 0;
}