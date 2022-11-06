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

pair < int, int > a[maxn];

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, m;
    scanf ( "%d%d", &n, &m );
    int ans = inf;
    for ( int j = 0; j < m; j++ ) {
    	scanf ( "%d%d", &a[j].f, &a[j].s );
    	ans = min( ans, a[j].s - a[j].f + 1 );
    }
    printf ( "%d\n", ans );
    int cur = 0;
    for ( int j = 0; j < n; j++ ) {
    	printf ( "%d ", cur );
    	++cur;
    	cur %= ans;
    }
    return 0;
}