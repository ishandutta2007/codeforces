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

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d", &n );
    for ( int j = 0; j < n; j++ )
    	scanf ( "%d", &a[j] );
    sort( a, a + n );
    int r = 3;
    while ( r < n && a[2] == a[r] )
    	++r;
    int l = 2;
    while ( l >= 0 && a[2] == a[l] )
    	--l;
    ++l;
    --r;
    if ( l == 2 ) {
    	printf ( "%d\n", r - l + 1 );
    	return 0; 
    }
    if ( l == 1 ) {
    	cout << 1LL * ( r - l + 1 ) * ( r - l ) / 2 << endl;
    	return 0;
    }
    cout << 1LL * ( r - l + 1 ) * ( r - l ) * ( r - l - 1 ) / 6 << endl;
    return 0;
}