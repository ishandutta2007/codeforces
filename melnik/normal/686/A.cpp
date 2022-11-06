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

const int maxn = 100500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    ll cur;
    scanf ( "%d%lld\n", &n, &cur );
    int ans = 0;
    for ( int j = 0; j < n; j++ ) {
        char t;
        int x;
        scanf ( "%c %d\n", &t, &x );
        if ( t == '+' )
            cur += 1LL * x;
        if ( t == '-' ) {
            if ( cur >= x )
                cur -= 1LL * x;
            else
                ++ans;
        }
    }
    printf ( "%lld %d\n", cur, ans );
    return 0;
}