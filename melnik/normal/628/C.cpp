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

const int maxn = 100500;
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
    int n, k;
    scanf ( "%d%d\n", &n, &k );
    gets( t );
    int j;
    int ma = 0;
    for ( j = 0; j < n; j++ )
        ma += max( t[j] - 'a', 'z' - t[j] );
    if ( ma < k ) {
        printf ( "-1" );
        return 0;
    }
    for ( j = 0; j < n; j++ ) {
        if ( t[j] - 'a' > 'z' - t[j] ) {
            if ( k >= t[j] - 'a' ) {
                k -= t[j] - 'a';
                t[j] = 'a';
            } else {
                t[j] -= k;
                k = 0;
            }
        } else {
            if ( k >= 'z' - t[j] ) {
                k -= 'z' - t[j];
                t[j] = 'z';
            } else {
                t[j] += k;
                k = 0;
            }
        }
    }
    puts( t );
    return 0;
}