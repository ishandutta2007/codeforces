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
    for ( j = 0; j < n; j++ )
        scanf ( "%d", &a[j] );
    sort( a, a + n );
    reverse( a, a + n );
    ll ans = 1LL * a[0];
    int cnt = a[0];
    for ( j = 1; j < n; j++ ) {
        if ( cnt ) --cnt;
        ans += 1LL * min( a[j], cnt );
        cnt = min( cnt, a[j] );
    }
    cout << ans;
    return 0;
}