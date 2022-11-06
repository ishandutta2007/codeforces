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


using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 405;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

vector < int > ans;

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, v;
    scanf ( "%d%d", &n, &v );
    for ( int j = 0; j < n; j++ ) {
        bool flag = false;
        int cnt;
        scanf ( "%d", &cnt );
        while ( cnt-- ) {
            int x;
            scanf ( "%d", &x );
            if ( x + 1 <= v )
                flag = true;
        }
        if ( flag )
            ans.pb( j + 1 );
    }
    int sz = ans.size();
    printf( "%d\n", sz );
    for ( int j = 0; j < sz; j++ )
        printf( "%d ", ans[j] );
    return 0;
}