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

const int maxn = 2e5 + 500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

pair < int, int > seg[maxn];

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n, j;
    ll ans = 0LL;
    scanf ( "%d", &n );
    for ( j = 0; j < n; j++ ) {
        scanf ( "%d", &seg[j].f );
        seg[j].s = j;
    }
    sort( seg, seg + n );
    for ( j = 1; j < n; j++ ) {
        ans += 1LL * abs( seg[j].s - seg[j - 1].s );
    }
    printf ( "%I64d\n", ans );
    return 0;
}