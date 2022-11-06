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

const int maxn = 505;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn][maxn];

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n, k;
    scanf ( "%d%d", &n, &k );
    int j, i;
    int m = n * n;
    for ( j = n - 1; j >= 0; j-- ) {
        for ( i = n - 1; i >= k - 1; i-- )
            a[j][i] = m--;
    }
    m = 1;
    for ( j = 0; j < n; j++ )
        for ( i = 0; i < k - 1; i++ )
            a[j][i] = m++;
    int ans = 0;
    for ( j = 0; j < n; j++ )
        ans += a[j][k - 1];
    printf ( "%d\n", ans );
    for ( j = 0; j < n; j++ ) {
        for ( i = 0; i < n; i++ )
            printf ( "%d ", a[j][i] );
        printf ( "\n" );
    }
    return 0;
}