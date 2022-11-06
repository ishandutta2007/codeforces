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

double a[20][20];

void recalc() {
	for ( int j = 0; j < 19; j++ )
		for ( int i = 0; i < 19; i++ )
			if ( a[j][i] > 1.0 ) {
				double odd = a[j][i] - 1.0;
				a[j][i] = 1;
				a[j + 1][i] += odd / 2.0;
				a[j + 1][i + 1] += odd / 2.0;
			}
		
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n, t;
    scanf ( "%d%d", &n, &t );
    for ( int j = 0; j < t; j++ ) {
    	a[0][0] += 1.0;
    	recalc();
    }
    int ans = 0;
    for ( int j = 0; j < n; j++ )
    	for ( int i = 0; i < n; i++ )
    		if ( fabs( a[j][i] - 1.0 ) < eps ) 
    			++ans;
    printf ( "%d\n", ans );
    return 0;
}