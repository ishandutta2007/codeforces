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
const int base = 1073676287;

int a[maxn];
int sufSum[maxn];

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d", &n );
    for ( int j = 0; j < n; j++ ) {
    	int x;
    	scanf ( "%d", &x );
    	++a[x];
    }
    ll ans = 0LL;
    for ( int j = maxn - 2; j >= 0; j-- )
    	sufSum[j] = sufSum[j + 1] + a[j];
    for ( int j = 1; j < maxn; j++ ) {
    	if ( !a[j] )
    		continue;
    	int curCnt = 0;
    	ll curAns = 0LL;
    	for ( int i = ( maxn / j ) * j; i >= j; i -= j ) {
    		curAns += 1LL * i * ( sufSum[i] - curCnt );
    		curCnt = sufSum[i];
    	}
    	ans = max( ans, curAns );
    }
    cout << ans << endl;
    return 0;
}