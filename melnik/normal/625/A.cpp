#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <ext\hash_set>
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

const int maxn = 1e5;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

bool correct( ll n, ll b, ll c, ll ans ) {
    if ( n - ( b - c ) * ans < c ) return 0;
    if ( n - ( b - c ) * ans > b ) return 0;
    return 1;
}

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    ll l = 0LL;
    ll r = ( 1LL * inf * inf ) / ( b - c );
    while ( r - l > 1LL ){
        ll mid = ( l + r ) >> 1;
        if ( n - ( b - c ) * mid >= b )
            l = mid + 1LL;
        else
            r = mid;
    }
    if ( correct( n, b, c, r ) )
        l = r;
    ll kol1 = n / a;
    l += ( n - ( b - c ) * l ) / a;
    cout << max( l, kol1 );
    return 0;
}