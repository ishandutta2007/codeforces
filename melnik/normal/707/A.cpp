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

char t[maxn];

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, m;
    scanf ( "%d%d\n", &n, &m );
    bool correct = true;
    for ( int j = 0; j < n; j++ ) {
    	gets( t );
    	m = strlen( t );
    	for ( int j = 0; j < m; j++ ) {
    		if ( t[j] == ' ' )
    			continue; 
    		if ( t[j] == 'W' )
    			continue;
    		if ( t[j] == 'B' )
    			continue;
    		if ( t[j] == 'G' )
    			continue;
    		correct = false;
    	}
    }
    if ( correct )
    	puts( "#Black&White" );
    else
    	puts( "#Color" );
    return 0;
}