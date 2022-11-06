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

const int maxn = 1e5;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int i[maxn];

int a1[25], a2[25];

void init() {
    for ( int y = 0; y < 25; y++ )
        a1[y] = 0;
    int l = 0;
    while ( i[0] > 0 ) {
        a1[l] = i[0] % 2;
        l++;
        i[0] /= 2;
    }
}

int is_correct ( int j ) {
    for ( int y = 0; y < 25; y++ )
        a2[y] = 0;
    int l = 0;
    while ( i[j] > 0 ) {
        a2[l] = i[j] % 2;
        l++;
        i[j] /= 2;
    }
    int ans = 0;
    for ( int y = 0; y < 25; y++ )
        ans += a1[y] ^ a2[y];
    return ans;
}

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
    int n, m, k, j, ans = 0;;
    scanf ( "%d%d%d", &n, &m, &k );
    for ( j = 1; j <= m; j++ )
        scanf ( "%d", &i[j] );
    scanf ( "%d", &i[0] );
    init();
    for ( j = 1; j <= m; j++ )
        if ( is_correct( j ) <= k ) ans++;
    printf ( "%d", ans );
    return 0;
}