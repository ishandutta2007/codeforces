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
#include <stack>
#include <bitset>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, m, d, cnt[ 21 ], id[ 100100 ], ans, c1, c2, msk = 0;
vector< int > s[ 21 ];
int st[ 21 ], fn[ 21 ];
bool f[ 21 ][ 1048579 ];

void rec( int pos )
{
    if ( pos == m )
    {
        if ( c1 == 0 || c2 == 0 ) return;
        int num = __builtin_popcount( msk );
        if ( __builtin_popcount( msk ) >= ans ) return;
        int inv = (1 << m) - msk - 1;
        for ( int i = 0; i < m; i++ ) 
            if ( msk & ( 1 << i ) )
                if ( f[i][inv] )
                    return;
        ans = __builtin_popcount( msk );
        return;
    }
    rec( pos + 1 );
    msk += (1 << pos); c1 += st[pos]; c2 += fn[pos];
    rec( pos + 1 );
    msk -= (1 << pos); c1 -= st[pos]; c2 -= fn[pos];
}

int main (int argc, const char * argv[])
{
    scanf("%d%d%d", &n, &m, &d); ans = m;
    for ( int i = 0; i < m; i++ )
    {
        int k; scanf("%d", &k);
        for ( int j = 0; j < k; j++ )
        {
            int a; scanf("%d", &a);
            id[a] = i;
            s[i].push_back( a );
        }
        sort( s[i].begin(), s[i].end() );
        if ( s[i][0] <= d ) st[i] = 1; else st[i] = 0;
        if ( n - d + 1 <= s[i].back() ) fn[i] = 1; else fn[i] = 0;
    }
    if ( d == n )
    {
        puts("1");
        return 0;
    }
    for ( int i = 1; i <= d; i++ ) cnt[ id[i] ]++;
    int l = 1, r = d + 1;
    while ( true )
    {
        int msk = 0;
        for ( int i = 0; i < m; i++ ) if ( cnt[i] > 0 ) msk += (1 << i);
        f[ id[r] ][ msk ] = true;
        if ( r == n ) break;
        cnt[ id[r] ]++; r++;
        cnt[ id[l] ]--; l++;
    }
    for ( int i = 0; i < m; i++ )
        for ( int j = 0; j < ( 1 << m ); j++ )
        {
            if ( !f[i][j] ) continue;
            for ( int k = 0; k < m; k++ ) f[i][ j | (1 << k) ] = true;
        }
    rec( 0 );
    printf("%d\n", ans);
    return 0;
}