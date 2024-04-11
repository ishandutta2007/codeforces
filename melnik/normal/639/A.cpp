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

const int maxn = 150500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn];
set < int > b;
set < int >::iterator it, it1;

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int  n, k, q;
    scanf ( "%d%d%d", &n, &k, &q );
    for ( int j = 1; j <= n; j++ )
        scanf ( "%d", &a[j] );
    while ( q-- ) {
        int type, x;
        scanf ( "%d%d", &type, &x );
        if ( type == 1 ) {
            if ( b.size() < k )
                b.insert( x );
            else {
                int mi = inf;
                it1 = b.begin();
                for ( it = b.begin(); it != b.end(); it++ )
                    if ( a[*it] < mi ) {
                        it1 = it;
                        mi = a[*it];
                    }
                if ( mi < a[x] ) {
                    b.erase( it1 );
                    b.insert( x );
                }
            }
        }
        if ( type == 2 ) {
            if ( b.find( x ) != b.end() )
                puts( "YES" );
            else
                puts( "NO" );
        }
    }
    return 0;
}