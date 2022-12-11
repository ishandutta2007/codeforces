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

int n, cnt[ 100100 ];
long long f[ 100100 ][ 2 ];

void upd( long long &a, long long b )
{
    a = max( a, b );
}

int main (int argc, const char * argv[])
{  
    cin >> n;
    for ( int i = 1; i <= n; i++ )
    {
        int a; cin >> a;
        cnt[ a ] += 1;
    }
    memset( f, -1, sizeof( f ) );
    f[ 0 ][ 0 ] = 0;
    for ( int i = 0; i < 100010; i++ )
    {
        upd( f[i + 1][0], f[i][1] );
        upd( f[i + 1][0], f[i][0] );
        if ( f[i][0] != -1 ) upd( f[i + 1][1], f[i][0] + 1ll * i * cnt[i] );
    }
    cout << max( f[ 100010 ][ 0 ], f[ 100010 ][ 1 ] ) << "\n";
    return 0;
}