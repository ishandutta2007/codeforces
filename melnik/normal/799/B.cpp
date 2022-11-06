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

set < pair < int, int > > a[10];

int q1[maxn];
int q2[maxn];
int q3[maxn];

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d", &n );
    for ( int j = 0; j < n; j++ )
    	scanf ( "%d", &q1[j] );
    for ( int j = 0; j < n; j++ )
    	scanf ( "%d", &q2[j] );
    for ( int j = 0; j < n; j++ )
    	scanf ( "%d", &q3[j] );
    for ( int j = 0; j < n; j++ ) {
    	a[q2[j]].insert( mp( q1[j], j ) );
    	a[q3[j]].insert( mp( q1[j], j ) );
    }
    int q;
    scanf ( "%d", &q );
    while ( q-- ) {
    	int x;
    	scanf ( "%d", &x );
    	if ( a[x].begin() == a[x].end() ) {
    		puts( "-1" );
    		continue;
    	}
    	pair < int, int > cur = *a[x].begin();
    	printf ( "%d\n", cur.f );
    	int pos = cur.s;
    	a[q2[pos]].erase( mp( q1[pos], pos ) );
    	a[q3[pos]].erase( mp( q1[pos], pos ) );
    }
    return 0;
}