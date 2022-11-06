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

const int maxn = 100500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

pair < pair < int, int >, int > a[maxn];

bool correct( int j, int i, int y ) {
    if ( j == y || i == y ) return 0;
//    int deltaX = inf;
    int deltaX = a[y].f.f - a[j].f.f;
    if ( !deltaX ) return 1;
    int q = __gcd( a[i].f.f - a[j].f.f, abs( a[i].f.s - a[j].f.s ) );
//    int deltaF = a[i].f.f - a[j].f.f;
//    deltaF /= q;
//    cout << deltaX << ' ' << q << ' ' << deltaX % ( ( a[i].f.f - a[j].f.f ) / q ) << endl;
    if ( deltaX % ( ( a[i].f.f - a[j].f.f ) / q ) ) return 1;
    ll deltaY = 1LL * ( ( a[i].f.s - a[j].f.s ) / q ) * ( deltaX / ( ( a[i].f.f - a[j].f.f ) / q ) );
    if ( 1LL * a[j].f.s + deltaY == 1LL * a[y].f.s ) return 0;
    return 1;
}

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n, j, ans1, ans2, ans3;
    scanf ( "%d", &n );
    for ( j = 0; j < n; j++ ) {
        scanf ( "%d%d", &a[j].f.f, &a[j].f.s );
        a[j].s = j + 1;
    }
    sort( a, a + n );
    ans1 = a[0].s;
    int q = 0;
    j = 0;
    while ( a[j].f.f == a[j + 1].f.f ) j++;
    ans2 = a[j + 1].s;
    int w = j + 1;
    j = 0;
    while ( j < n ) {
        if ( correct( q, w, j ) ) {
            ans3 = a[j].s;
            break;
        }
        j++;
    }
//    cout << correct( q, w, j ) << endl;
    cout << ans1 << ' ' << ans2 << ' ' << ans3;
    return 0;
}