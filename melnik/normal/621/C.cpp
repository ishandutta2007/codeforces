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

pair < int, int > a[maxn];
int all[maxn];
int kol[maxn];

void calc( int j, int p ) {
    all[j] = a[j].s - a[j].f + 1;
    kol[j] = a[j].s / p - ( a[j].f - 1 ) / p;
}

ld calc2( int j ) {
    return (ld) ( (ld) kol[j] / all[j] ) * (ld) ( (ld) kol[j - 1] / all[j - 1] ) * (ld) 2000;
}

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n, p, x, y, j;
    scanf ( "%d%d", &n, &p );
    for ( j = 0; j < n; j++ ) {
        scanf ( "%d%d", &a[j].f, &a[j].s );
        calc( j, p );
    }
    ld ans = 0;
    for ( j = 0; j < n; j++ )
        ans += (ld) 4000.0 * kol[j] / all[j];
    for ( j = 1; j < n; j++ )
        ans -= calc2( j );
    ans -= (ld) ( (ld) kol[n - 1] / all[n - 1] ) * (ld) ( (ld) kol[0] / all[0] ) * (ld) 2000;
    cout << fixed << setprecision( 20 ) << ans;
    return 0;
}