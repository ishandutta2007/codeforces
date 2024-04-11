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

bool correct( int x, int y ) {
	if ( x < 0 || y < 0 )
		return 0;
	if ( x > 7 || y > 7 )
		return 0;
    return 1;
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    char t;
    t = getchar();
    int x = t - 'a';
    t = getchar();
    int y = t - '1';
    int ans = 0;
    // cout << x << ' ' << y << endl;
    ans += correct( x - 1, y - 1 );
    ans += correct( x - 1, y - 0 );
    ans += correct( x - 1, y + 1 );
    ans += correct( x - 0, y - 1 );

    ans += correct( x - 0, y + 1 );
    ans += correct( x + 1, y - 1 );
    ans += correct( x + 1, y - 0 );
    ans += correct( x + 1, y + 1 );

    printf ( "%d\n", ans );
    return 0;
}