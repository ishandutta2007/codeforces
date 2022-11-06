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

char t[maxn][10];

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d\n", &n );
    bool need = true;
    for ( int j = 0; j < n; j++ ) {
    	gets( t[j] );
    	if ( need && t[j][0] == 'O' && t[j][1] == 'O' ) {
    		t[j][0] = t[j][1] = '+';
    		need = false;
    	}
    	if ( need && t[j][3] == 'O' && t[j][4] == 'O' ) {
    		t[j][3] = t[j][4] = '+';
    		need = false;
    	}
    }
    if ( need )
    	puts( "NO" );
    else {
    	puts( "YES" );
	    for ( int j = 0; j < n; j++ )
	    	puts( t[j] );
	}
    return 0;
}