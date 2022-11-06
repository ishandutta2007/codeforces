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
#include <cstdlib>


using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 1e2;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1e9 + 7;

int cost[maxn];

int main()
{
//    ios_base::sync_with_stdio( 0 );
//    freopen( "input.txt", "r", stdin );
//    freopen( ".out", "w", stdout );
    cost[0] = 500;
    cost[1] = 1000;
    cost[2] = 1500;
    cost[3] = 2000;
    cost[4] = 2500;
    int m[maxn], w[maxn], h1, h2, j;
    double ans = 0;
    for ( j = 0; j < 5; j++ )
        scanf( "%d", &m[j] );
    for ( j = 0; j < 5; j++ )
        scanf( "%d", &w[j] );
    scanf ( "%d%d", &h1, &h2 );
    for ( j = 0; j < 5; j++)
        ans += max( 0.3 * cost[j], ( 1.0 - m[j] / 250.0 ) * cost[j] - 50.0 * w[j] );
    ans += 100.0 * h1 - 50.0 * h2;
    printf ( "%d", (int) ceil( ans ) );
    return 0;
}