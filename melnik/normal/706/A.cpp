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

ld sq( int c ) {
	return c * c;
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int a, b;
    int n;
    ld mi = inf;
    scanf ( "%d%d%d", &a, &b, &n );
    while ( n-- ) {
    	int A, B, V;
    	scanf ( "%d%d%d", &A, &B, &V );
    	mi = min( mi, sqrt( sq( A - a ) + sq( B - b ) ) / V );
    }
    cout << fixed << setprecision( 20 ) << mi << endl;
    return 0;
}