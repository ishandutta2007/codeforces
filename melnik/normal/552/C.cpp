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

const int maxn = 105;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn];

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, m;
    scanf ( "%d%d", &n, &m );
    int pos = 0;
    while ( m ) {
        a[pos++] = m % n;
        m /= n;
    }
    for ( int j = 0; j < maxn - 1; j++ ) {
        a[j + 1] += a[j] / n;
        a[j] %= n;
        if ( a[j] <= 1 )
            continue;
        ++a[j + 1];
        a[j] -= n;
        if ( a[j] != -1 ) {
            puts( "NO" );
            return 0;
        }
    }
    puts( "YES" );
    return 0;
}