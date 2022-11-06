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
    int n, j, i[maxn], l, r, kol = 0;
    scanf ( "%d", &n );
    for ( j = 0; j < n; j++ )
        scanf ( "%d", &i[j] );
    l = 0;
    while ( l < n )
        if ( i[l] == 0 ) l++; else break;
    r = n - 1;
    while ( r >= 0 )
        if ( i[r] == 0 ) r--; else break;
    n = r + 1;
    while ( l < n ) {
        if ( i[l] == 1 ) kol++;
        else {
            r = l;
            while ( r < n ){
                if ( i[r] != 0 ) break;
                r++;
            }
            if ( r - l > 1 )
                l = r - 1; else {
                    kol += r - l;
                    l = r - 1;
                }
        }

        l++;
    }
    printf ( "%d", kol );
    return 0;
}