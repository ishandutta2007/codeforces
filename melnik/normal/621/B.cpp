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

const int maxn = 10500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn];
int kol1[maxn] = {0};
int kol2[maxn] = {0};

void calc1 ( int x, int y ) {
    int delta = min( x, y );
    x -= delta, y -= delta;
    if ( x == 0 && y == 0 )  {
        kol1[5000]++;
        return;
    }
    if ( x == 0 ) {
        kol1[y]++;
        return;
    }
    if ( y == 0 )
        kol1[x + 1000]++;
//    kol1[max( x - delta, y - delta )]++;
//    delta = min( 1000 - x, y );
//    kol2[max( 1000 - x - delta, y - delta )]++;
}

void calc2( int x, int y ) {
    int delta = min( x, y );
    x -= delta, y -= delta;
    if ( x == 0 && y == 0 )  {
        kol2[5000]++;
        return;
    }
    if ( x == 0 ) {
        kol2[y]++;
        return;
    }
    if ( y == 0 )
        kol2[x + 1000]++;

}


int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n, j, x, y;
    scanf ( "%d", &n );
    for ( j = 0; j < n; j++ ) {
        scanf ( "%d%d", &x, &y );
        calc1( x, y );
        calc2( 1000 - x + 1, y );
    }
    ll ans = 0LL;
    for ( j = 0; j < maxn; j++ ) {
        if ( kol1[j] > 1 ) {
            ans += 1LL * kol1[j] * ( kol1[j] - 1 ) / 2LL;
        }
        if ( kol2[j] > 1 ) {
            ans += 1LL * kol2[j] * ( kol2[j] - 1 ) / 2LL;
        }
    }
    cout << ans;
    return 0;
}