#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
//#include <ext\hash_set>
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

const int maxn = 1050;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

char t[maxn][10];

int calc( int j, int i ) {
    int cur = 0;
    for ( int y = 0; y < 6; y++ )
        cur += t[j][y] != t[i][y];
    return max( 0, ( cur - 1 ) / 2 );
}

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d\n", &n );
    for ( int j = 0; j < n; j++ )
        gets( t[j] );
    int ans = 6;
    for ( int j = 0; j < n; j++ )
        for ( int i = j + 1; i < n; i++ )
            ans = min( ans, calc( j, i ) );
    printf ( "%d\n", ans );
    return 0;
}