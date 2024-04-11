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

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 1000500;
const int inf = 2e9;
const double eps = 1e-8;

int b[maxn], a[maxn];

multimap < int, int > f;
multimap < int, int >:: iterator it;

int main()
{
    int n, m, x, j, pff = 0;
    scanf ( "%d%d", &n, &m );
    for ( j = 0; j < n; j++ ) {
        scanf ( "%d", &x );
        f.insert( mp ( x, j ) );
    }
    for ( j = 0; j < m; j++ )
        scanf ( "%d", &b[j] );
    for ( j = 0; j < m; j++ ) {
        it = f.find( b[j] );
        pair < int, int > z = *it;
        if ( it == f.end() ) {
            printf ( "Impossible" );
            return 0;
        }
        f.erase( it );
        a[j] = z.s;
        it = f.find( b[j] );
        if ( it != f.end() ) pff = 1;
        f.insert( z );
    }
    if ( pff != 0 ) {
        printf ( "Ambiguity\n" );
        return 0;
    }
    printf ( "Possible\n" );
    for ( j = 0; j < m; j++ )
        printf ( "%d ", a[j] + 1 );
    return 0;
}