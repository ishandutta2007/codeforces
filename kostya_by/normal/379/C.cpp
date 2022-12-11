#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <stack>
#include <bitset>
#include <sstream>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, b[ 300300 ], mn = 0;
set< pair< int, int > > s;

int main (int argc, const char * argv[])
{
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ )
    {
        int a; scanf("%d", &a);
        s.insert( mp( a, i ) );
    }
    while ( s.size() )
    {
        pair< int, int > p = *s.begin(); s.erase( s.begin() );
        int a = p.first;
        int id = p.second;
        b[id] = max( a, mn + 1 );
        mn = b[id];
    }
    for ( int i = 1; i <= n; i++ ) printf("%d ", b[i]);
    return 0;
}