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

const int maxn = 2e6 + 100;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

pair < int, int > fa[maxn];
list < int > ans;

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n, k, j, a, b;
    scanf ( "%d%d", &n, &k );
    for ( j = 0; j < n; j++ ) {
        scanf ( "%d%d", &a, &b );
        fa[j * 2] = mp( a, 0 );
        fa[j * 2 + 1] = mp( b, 1 );
    }
    sort ( fa, fa + 2 * n );
    n = 2 * n;
    int kol = 0;
    for ( j = 0; j < n; j++ ) {
        if ( !fa[j].s ) {
            kol++;
            if ( kol == k ) ans.pb( fa[j].f );
            continue;
        }
        kol--;
        if ( kol + 1 == k )
            ans.pb( fa[j].f );
    }
    printf ( "%d\n", ans.size() / 2 );
    kol = ans.size();
    for ( j = 0; j < kol; j += 2 ) {
        printf ( "%d ", ans.front() );
        ans.pop_front();
        printf ( "%d\n", ans.front() );
        ans.pop_front();
    }
    return 0;
}