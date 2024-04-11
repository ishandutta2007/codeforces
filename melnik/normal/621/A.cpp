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

int a[maxn];

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n, j;
    scanf( "%d", &n );
    for ( j = 0; j < n; j++ )
        scanf ( "%d", &a[j] );
    ll ans = 0LL;
    int mi = inf;
    int kol = 0;
    for ( j = 0; j < n; j++ ) {
        if ( a[j] % 2 ) mi = min( a[j], mi ), kol++;
        ans += 1LL * a[j];
    }
    if ( mi != inf && kol % 2 ) ans -= 1LL * mi;
    cout << ans;
    return 0;
}