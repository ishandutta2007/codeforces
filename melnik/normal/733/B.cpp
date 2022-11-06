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

int a[maxn];
int b[maxn];

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d", &n );
    int sum1 = 0;
    int sum2 = 0;
    for ( int j = 0; j < n; j++ ) {
    	scanf ( "%d%d", &a[j], &b[j] );
    	sum1 += a[j];
    	sum2 += b[j];
    }
    int maxAns = abs( sum1 - sum2 );
    int pos = -1;
    for ( int j = 0; j < n; j++ ) {
    	sum1 -= a[j];
    	sum2 -= b[j];
    	sum1 += b[j];
    	sum2 += a[j];
    	if ( abs( sum1 - sum2 ) > maxAns ) {
    		maxAns = abs( sum1 - sum2 );
    		pos = j;
    	}
    	sum1 += a[j];
    	sum2 += b[j];
    	sum1 -= b[j];
    	sum2 -= a[j];
    }
    printf ( "%d\n", pos + 1 );
    return 0;
}