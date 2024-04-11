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
#include <cassert>
#include <stack>
#include <bitset>
#include <sstream>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, m, k, p;
long long r[ 1111 ], c[ 1111 ];
long long f[ 1111111 ], g[ 1111111 ];

void process( long long a[], int n, int mul, long long result[] )
{
    priority_queue< long long > q;
    for ( int i = 1; i <= n; i++ ) q.push( a[i] );
    long long sum = 0;
    for ( int it = 1; it <= k; it++ )
    {
        long long cur = q.top(); q.pop();
        //cout << cur << "\n";
        sum += cur;
        cur -= p * mul;
        q.push( cur );
        result[ it ] = sum;
    }
   // cout << "----------------------\n";
}

int main (int argc, const char * argv[])
{
    scanf("%d%d%d%d", &n, &m, &k, &p);
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
        {
            int a;
            scanf("%d", &a);
            r[i] += a;
            c[j] += a;
        }
    process( r, n, m, f );
    process( c, m, n, g );
    long long answer = -inf;
    for ( int i = 0; i <= k; i++ ) answer = max( answer, f[i] + g[k - i] - 1ll * i * (k - i) * p );
    cout << answer << "\n";
    return 0;
}