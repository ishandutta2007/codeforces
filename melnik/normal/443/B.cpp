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

const int maxn = 405;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

char t[maxn];

inline bool isEqual( char x, char y ) {
    if ( x == '?' || y == '?' )
        return true;
    return x == y;
}

bool correct( int l, int len ) {
    for ( int j = l; j < l + len / 2; j++ )
        if ( !isEqual( t[j], t[j + len / 2] ) )
            return false;
    return true;
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    gets( t );
    int len = strlen( t );
    int k;
    scanf ( "%d", &k );
    for ( int j = len; j < len + k; j++ )
        t[j] = '?';
    len += k;
    for ( int j = len; j >= 0; j-- ) {
        if ( j & 1 )
            continue;
        for ( int l = 0; l < len - j + 1; l++ )
            if ( correct( l, j ) ) {
                printf( "%d\n", j );
                return 0;
            }
    }
    return 0;
}