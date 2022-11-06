#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
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
#include <cassert>


using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 1000500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;


int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, a, b, c = 0;
    scanf ( "%d%d%d", &n, &a, &b );
    int ans = 0;
    for ( int j = 0; j < n; j++ ) {
        int type;
        scanf ( "%d", &type );
        if ( type == 1 ) {
            if ( a ) {
                --a;
                continue;
            }
            if ( b ) {
                --b;
                ++c;
                continue;
            }
            if ( c ) {
                --c;
                continue;
            }
            ++ans;
            continue;
        }
        if ( type == 2 ) {
            if ( b )
                --b;
            else
                ans += 2;
        }
    }
    printf( "%d\n", ans );
    return 0;
}