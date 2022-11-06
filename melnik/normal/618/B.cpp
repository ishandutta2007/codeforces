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

const int maxn = 55;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn][maxn];
int ans[maxn] = {0};
bool used[maxn];
bool found[maxn] = {0};

bool correct( int j, int n ) {
    int i;
    for ( i = 0; i < maxn; i++ )
        used[i] = false;
    for ( i = 0; i < n; i++ )
        if ( a[j][i] != inf && a[j][i] != 0 ) used[a[j][i]] = true;
    int kol = 0;
    for ( i = 0; i < maxn; i++ )
        kol += used[i];
    if ( kol == 1 ) return 1;
    return 0;
}

int find_ans( int j, int n ) {
    int i;
    for ( i = 0; i < maxn; i++ )
        used[i] = false;
    for ( i = 0; i < n; i++ )
        if ( a[j][i] != inf && a[j][i] != 0 ) used[a[j][i]] = true;
    i = 0;
    while ( i < maxn && !used[i] ) i++;
    if ( i == maxn ) return n;
    int ans = i;
    for ( i = 0; i < maxn; i++ )
        a[i][j] = inf;
    return ans;
}

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n, i, j, it;
    scanf ( "%d", &n );
    for ( j = 0; j < n; j++ )
        for ( i = 0; i < n; i++ )
            scanf ( "%d", &a[j][i] );
    for ( it = 0; it < n; it++ ) {
        int pos;
        for ( j = 0; j < n; j++ ) {
            if ( !ans[j] ) pos = j;
            if ( !found[j] && correct( j, n ) ) break;
        }
        found[j] = 1;
//        if ( j == n )
        ans[pos] = find_ans( j, n );
    }
    for ( j = 0; j < n; j++ )
        cout << ans[j] << ' ';
    return 0;
}