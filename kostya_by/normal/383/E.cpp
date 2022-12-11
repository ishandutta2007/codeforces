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

int n, lim;
int f[ 16777216 ];
string buf;

void solve( int l, int r )
{
    if ( l == r ) return;
    int x = ( r - l + 1 ) / 2;
    solve( l, l + x - 1 );
    solve( l + x, r );
    for ( int i = 0; i < x; i++ ) f[ l + x + i ] += f[ l + i ];  
}

int main (int argc, const char * argv[])
{
    cin >> n;
    for ( int i = 0; i < n; i++ )
    {
        cin >> buf;
        int msk = 0;
        for ( int j = 0; j < buf.size(); j++ ) msk |= 1 << ( buf[j] - 'a' );
        f[ msk ]++;
    }
    solve( 0, 16777215 );
    long long ans = 0, tmp = 0;
    for ( int i = 0; i < 16777216; i++ ) 
    {
        tmp = n - f[ i ];
        ans ^= tmp * tmp;
    }
    cout << ans << "\n";
    return 0;
}