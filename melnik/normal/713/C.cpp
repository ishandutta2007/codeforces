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

const int maxn = 3050;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn];
int b[maxn];

vector < pair < int, ll > > curAns;
vector < pair < int, ll > > newAns;

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d", &n );
    for ( int j = 0; j < n; j++ ) {
    	scanf ( "%d", &a[j] );
    	a[j] -= j;
    	b[j] = a[j];
    }
    sort( b, b + n );
    curAns.pb( mp( a[0], 0LL ) );
    for ( int j = 0; j < n; j++ )
    	if ( a[j] < a[0] )
    		curAns.pb( mp( a[j], 1LL * abs( a[0] - a[j] ) ) );
    sort( curAns.begin(), curAns.end() );
    for ( int j = 1; j < n; j++ ) {
    	int l = 0;
    	ll mi = 1LL * inf * inf;
    	for ( int i = 0; i < n; i++ ) {
    		while ( l < n && curAns[l].f <= b[i] ) {
    			mi = min( mi, curAns[l].s );
    			++l;
    		}
    		if ( mi != 1LL * inf * inf )
    			newAns.pb( mp( b[i], mi + 1LL * abs( a[j] - b[i] ) ) );
       	}
    	curAns = newAns;
    	newAns.clear();
    }
    ll mi = 1LL * inf * inf;
    for ( int j = 0; j < curAns.size(); j++ )
    	mi = min( mi, curAns[j].s );
    cout << mi << endl;
    return 0;
}