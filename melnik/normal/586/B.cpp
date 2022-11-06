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

using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 1e3;
const int inf = 2e9;

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
    //ios_base::sync_with_stdio(false);
    int n, j, i[maxn][2], b[maxn], sum[maxn][2], kol1 = inf, kol2 = inf, kol;
    scanf ( "%d", &n );
    for ( j = 1; j < n; j++ )
        scanf ( "%d", &i[j][0] );
    for ( j = 0; j < n - 1; j++ )
        scanf ( "%d", &i[j][1] );
    for ( j = 0; j < n; j++ )
        scanf ( "%d", &b[j] );
    sum[0][0] = 0;
    sum[n - 1][1] = 0;
    for ( j = 1; j < n; j++ )
        sum[j][0] = sum[j - 1][0] + i[j][0];
    for ( j =  n - 2; j >= 0; j-- )
        sum[j][1] = sum[j + 1][1] + i[j][1];
    for ( j = 0; j < n; j++ )
        kol1 = min ( kol1, sum[j][0] + sum[j][1] + b[j] );
    kol = kol1;
    for ( j = 0; j < n; j++ ) {
        int h = sum[j][0] + sum[j][1] + b[j];
        if ( h == kol1 ) kol1 = -inf; else
            kol2 = min ( kol2, h );
    }
    printf ( "%d", kol + kol2 );
    return 0;
}