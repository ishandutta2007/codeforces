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

int a[maxn];

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n, j;
    scanf ( "%d", &n );
    bool correct = 0;
    for ( j = 0; j < n; j++ ) {
        scanf ( "%d", &a[j] );
        correct = max( correct, a[j] > 0 );
    }
    if ( !correct ) {
        printf ( "0\n" );
        return 0;
    }
    int l, r;
    l = r = 0;
    ll ans = 1LL;
    while ( !a[l] ) l++;
    r = l;
    while ( l < n ) {
        r = l + 1;
        while ( r < n && !a[r] )
            r++;
        if ( r == n ) break;
        ans *= 1LL * ( r - l );
        l = r;
    }
    cout << ans;
    return 0;
}