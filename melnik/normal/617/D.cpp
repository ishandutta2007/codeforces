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

pair < int, int > a[3];

int calc( int j, int i, int y ) {
    j--;
    i--;
    y--;
    int ans = 0;
    if ( a[j].f != a[i].f && a[j].s != a[i].s ) ans += 2;
        else ans++;
    if ( ans == 2 ) {
        return 10;
//        if ( a[i].f == a[y].f || a[i].s == a[y].s ) return ans;
//        if ( a[y].f < a[i].f && a[y].s < a[i].s ) return ans + 2;
//        return ++ans;
    }
    if ( a[j].f == a[i].f ) {
        if ( a[y].f == a[i].f ) return ans;
        if ( a[j].s > a[i].s ) swap( i, j );
        if ( a[y].s < a[i].s && a[y].s > a[j].s ) return ans + 2;
        return ++ans;
    }
    if ( a[y].s == a[i].s ) return ans;
    if ( a[j].f > a[i].f ) swap( i, j );
    if ( a[y].f < a[i].f && a[y].f > a[j].f ) return ans + 2;
    return ++ans;
}

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n = 3, j;
    for ( j = 0; j < n; j++ )
        scanf ( "%d%d", &a[j].f, &a[j].s );
    int ans = 3;
    ans = min( calc( 1, 2, 3 ), ans );
    ans = min( calc( 1, 3, 2 ), ans );
    ans = min( calc( 2, 1, 3 ), ans );
    ans = min( calc( 2, 3, 1 ), ans );
    ans = min( calc( 3, 1, 2 ), ans );
    ans = min( calc( 3, 2, 1 ), ans );
    cout << ans;
    return 0;
}