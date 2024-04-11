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
int used[maxn];
int timer;
int it;

void dfs( int v, int start ) {
	used[v] = timer;
	++it;
	int to = a[v];
	if ( !used[to] ) {
		dfs( to, start );
		return;
	}
	if ( used[to] != timer ) {
		puts( "-1" );
		exit( 0 );
	}
	if ( start != to ) {
		puts( "-1" );
		exit( 0 );
	}
}

vector < int > b;

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d", &n );
    for ( int j = 0; j < n; j++ ) {
    	scanf ( "%d", &a[j] );
    	--a[j];
    }
    for ( int j = 0; j < n; j++ )
    	if ( !used[j] ) {
    		++timer;
    		it = 0;
    		dfs( j, j );
    		if ( it % 2 == 0 )
                it /= 2;
    		b.pb( it );
    	}
    ull cur = b[0];
    int sz = b.size();
    for ( int j = 1; j < sz; j++ )
    	cur *= 1ULL * ( b[j] / __gcd( cur, 1ULL * b[j] ) );
    cout << cur << endl;
    return 0;
}