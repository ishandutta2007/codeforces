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

const int maxn = 150;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

bool used[maxn] = { false };

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n, m, j, k, x, i;
    scanf ( "%d%d", &n, &m );
    for ( j = 0; j < n; j++ ) {
        scanf ( "%d", &k );
        for ( i = 0; i < k; i++ ) {
            scanf ( "%d", &x );
            used[x] = 1;
        }
    }
    for ( j = 1; j <= m; j++ )
        if ( !used[j] ) {
            printf ( "NO" );
            return 0;
        }
    printf ( "YES" );
    return 0;
}