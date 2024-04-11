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

const int maxn = 5050;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn];
int b[maxn];
int ans[maxn];

void init() {
    for ( int j = 0; j < maxn; j++ )
        b[j] = 0;
}

void update( int r, pair < int, int > &curAns ) {
    if ( b[a[r]] < curAns.f )
        return;
    if ( a[r] > curAns.s && b[a[r]] == curAns.f )
        return;
    curAns = mp( b[a[r]], a[r] );
}

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
    for ( int l = 0; l < n; l++ ) {
        init();
        pair < int, int > curAns = mp( 0, 1 );
        for ( int r = l; r < n; r++ ) {
            ++b[a[r]];
            update( r, curAns );
            ++ans[curAns.s];
        }
    }
    for ( int j = 1; j <= n; j++ )
        printf ( "%d ", ans[j] );
    return 0;
}