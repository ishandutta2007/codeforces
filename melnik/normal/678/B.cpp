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

int calc( int x ) {
	if ( x % 400 == 0 )
		return 366;
	if ( x % 4 == 0 && x % 100 )
		return 366;
	return 365;
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int cur;
    scanf ( "%d", &cur );
    int old = cur;
    int pass = 0;
    while ( !pass || pass % 7 || calc( old ) != calc( cur ) )
    	pass += calc( ++cur );
    printf ( "%d\n", cur );
    return 0;
}