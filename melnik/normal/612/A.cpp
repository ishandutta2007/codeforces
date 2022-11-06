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

char t[maxn];

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n, p, q;
    scanf ( "%d%d%d\n", &n, &p, &q );
    gets ( t );
    int kol = 0;
    int ans = inf;
    for ( kol = 0; kol <= n / p; kol++ ) {
        if ( ( n - kol * p ) % q == 0 && ans == inf )
            ans = kol;
    }
    if ( ans == inf ) {
        printf ( "-1\n" );
        return 0;
    }
    kol = ans;
    printf ( "%d\n", kol + ( n - kol * p ) / q );
    int j, l, num = 0;
    for ( j = 0; j < kol; j++ ) {
        for ( l = 0; l < p; l++ ) {
            printf ( "%c", t[num] );
            num++;
        }
        printf ( "\n" );
    }
    kol = ( n - kol * p ) / q;
    for ( j = 0; j < kol; j++ ) {
        for ( l = 0; l < q; l++ ) {
            printf ( "%c", t[num] );
            num++;
        }
        printf ( "\n" );
    }
    return 0;
}