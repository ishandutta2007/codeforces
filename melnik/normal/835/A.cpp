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

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int a, v1, v2, t1, t2;
    scanf ( "%d%d%d%d%d", &a, &v1, &v2, &t1, &t2 );
    int cnt1 = a * v1 + 2 * t1;
    int cnt2 = a * v2 + 2 * t2;
    if ( cnt1 == cnt2 ) {
    	puts( "Friendship" );
    	return 0;
    }
    if ( cnt1 < cnt2 )
    	puts( "First" );
    else
    	puts( "Second" );
    return 0;
}