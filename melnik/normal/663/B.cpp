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

char t[maxn];

void init( ll &ans, char x ) {
    x -= '0';
    if ( x == 0 ) ans = 1990;
    if ( x == 1 ) ans = 1991;
    if ( x == 2 ) ans = 1992;
    if ( x == 3 ) ans = 1993;
    if ( x == 4 ) ans = 1994;
    if ( x == 5 ) ans = 1995;
    if ( x == 6 ) ans = 1996;
    if ( x == 7 ) ans = 1997;
    if ( x == 8 ) ans = 1998;
    if ( x == 9 ) ans = 1989;
}

void solve() {
    gets( t );
    int r = strlen( t );
    int l = 3;
    ll ans;
    --r;
    init( ans, t[r] );
    int cur = t[r--] - '0';
    ll curSt = 10LL;
    while ( r > l ) {
        cur += ( t[r] - '0' ) * (int)curSt;
        curSt *= 10LL;
        ll govno = ans % curSt;
        if ( govno >= cur )
            ans += curSt;
        ans /= curSt;
        ans *= curSt;
        ans += 1LL * cur;
        --r;
    }
    cout << ans << endl;
}

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int q;
    scanf ( "%d\n", &q );
    while ( q-- )
        solve();
    return 0;
}