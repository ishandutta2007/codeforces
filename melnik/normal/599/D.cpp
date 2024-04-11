#include <iostream>
#include <fstream>
#include <stdio.h>
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
#include <cstdlib>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <time.h>
#include <ctime>
#include <iterator>
#include <cstdio>


using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define s second
#define pb push_back
#define mp make_pair

const int maxn = 10000500;
const int inf = 2e9;
const double eps = 1e-8;

pair < int, ll > z[maxn];

int main()
{
    int n, ans = 0, j;
    ll x, m = 1LL;
    scanf ( "%I64d", &x );
    for ( n = 1; n <= m; n++ ) {
        ll f = 6LL * x + 1LL * n * n * n - 1LL * n;
        ll del = 3LL * n * n + 3LL * n;
//        ull f = 6uLL * x + 4uLL * n * n * n;
//        ull del = 6uLL * n * n + 3uLL * n;
        if ( f % del == 0 && n <= f / del) {
            z[ans] = mp( n, f / del );
            ans++;
        }
        m = f / del;
    }

#define f first
    int nans;
    if ( z[ans - 1].f == z[ans - 1].s ) nans = 2 * ans - 1; else nans = 2 * ans;
    printf ( "%d\n", nans );
    for ( j = 0; j < ans; j++ )
        printf ( "%d %I64d\n", z[j].first, z[j].s );
    if ( z[ans - 1].f == z[ans - 1].s ) j = ans - 2; else j = ans - 1;
    for ( ; j >= 0; j-- )
        printf ( "%I64d %d\n", z[j].s, z[j].f );
    return 0;
}