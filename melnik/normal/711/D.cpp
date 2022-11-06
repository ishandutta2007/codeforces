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

const int maxn = 200500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1e9 + 7;

int a[maxn];
int Time[maxn];
int used[maxn];
int timer = 1;
int st[maxn];
int ans = 1;
int cnt;

void dfs( int v, int curTime ) {
    used[v] = timer;
	if ( Time[v] ) {
		ans = ( 1LL * ans * ( st[curTime - Time[v]] - 2 ) ) % base;
		cnt -= curTime - Time[v];
		return;
	}
	Time[v] = curTime++;
	if ( used[a[v]] == timer || !used[a[v]] )
        dfs( a[v], curTime );
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d", &n );
    cnt = n;
    st[0] = 1;
    for ( int j = 1; j < maxn; j++ )
    	st[j] = ( 2 * st[j - 1] ) % base;
    for ( int j = 1; j <= n; j++ )
    	scanf ( "%d", &a[j] );
    for ( int j = 1; j <= n; j++ )
    	if ( !used[j] ) {
    		dfs( j, 1 );
            ++timer;
    	}
    ans = ( 1LL * ans * st[cnt] ) % base;
    printf ( "%d\n", ans );
    return 0;
}