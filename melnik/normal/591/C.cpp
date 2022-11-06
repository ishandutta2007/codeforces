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

const int maxn = 5e5 + 100;
const int inf = 2e9;
const double eps = 1e-10;

int i[maxn], b[maxn];

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
    int n, k, ma = 0, j;
    scanf ( "%d", &n );
    for ( k = 0; k < n; k++ ) {
        scanf ( "%d", &i[k] );
    }
    b[0] = 1;
    b[n - 1] = 1;
    for ( k = 1; k < n - 1; k++ )
        if ( i[k] == i[k + 1] || i[k] == i[k - 1] )
            b[k] = 1; else
            b[k] = 0;
    int l = 0, r = 0;
    while ( l < n ) {
        if ( b[l] == 0 ) {
            r = l;
            while ( b[r] == 0 ) r++;
            ma = max ( ma, r - l );
            if ( ( r - l ) % 2 == 0 ) {
                int mid = l + ( r - l ) / 2;
                for ( j = l; j < mid; j++ )
                    i[j] = i[l - 1];
                for ( j = mid; j < r; j++ )
                    i[j] = i[r];
            } else {
                for ( j = l; j < r; j++ )
                    i[j] = i[r];
            }
            l = r;
        } else l++;
    }
    printf ( "%d\n", ma / 2 + ma % 2 );
    for ( j = 0; j < n; j++ )
        printf ( "%d ", i[j] );
    return 0;
}