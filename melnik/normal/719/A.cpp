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
    if ( n == 1 && !a[n - 1] ) {
    	puts( "UP" );
    	return 0;
    }
    if ( n == 1 && a[n - 1] == 15 ) {
    	puts( "DOWN" );
    	return 0;
    }
    if ( n == 1 ) {
    	puts( "-1" );
    	return 0;
    }
    if ( !a[n - 1] ) {
    	puts( "UP" );
    	return 0;
    }
    if ( a[n - 1] == 15 ) {
    	puts( "DOWN" );
    	return 0;
    }
    if ( a[n - 1] > a[n - 2] )
    	puts( "UP" );
    else
    	puts( "DOWN" );
    return 0;
}