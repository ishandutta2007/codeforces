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

const int maxn = 200500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn];
int b[maxn];
list < int > odd[maxn];

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d", &n );
    for ( int j = 0; j < n; j++ )
        scanf ( "%d", &a[j] );
    int cur = 1;
    int l, r;
    l = r = 0;
    while ( l < n ) {
        r = l + 1;
        while ( r < n && a[l] == a[r] ) {
            if ( a[r] == 0 )
                a[r] = inf;
            else
                a[r] = cur;
            ++r;
        }
        if ( a[l] == 0 )
            a[l] = inf;
        else
            a[l] = cur;
        if ( a[l] != inf )
            ++cur;
        l = r;
    }
    for ( int j = 0; j < n; j++ )
        b[j] = a[j];
    sort( b, b + n );
    for ( int j = 0; j < n; j++ ) {
        if ( a[j] != inf && a[j] != b[j] )
            odd[a[j]].pb( j );
    }
    int ans = 0;
    for ( int j = 0; j < n; j++ )
        if ( b[j] != inf && a[j] != b[j] ) {
            int need = b[j];
            int id = odd[need].front();
            odd[need].pop_front();
            swap( a[j], a[id] );
            ++ans;
        }
    printf ( "%d", ans );
    return 0;
}