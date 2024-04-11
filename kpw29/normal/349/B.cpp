
 #include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int n, ans[ 1000001 ];
int ct[ 20 ], pct = 0;
int main()
{
    int minn = 1 << 30, min_i;
    scanf ( "%d", &n );
    for ( int i = 1; i < 10; i ++ )
    {
        scanf ( "%d", &ct[ i ] );
        if ( ct[ i ] <= minn )
        {
            minn = ct[ i ];
            min_i = i;
        }
    }
    int k = n / minn;
    for ( int i = 1; i <= k; i ++ ) ans[ i ] = min_i;
    if ( k == 0 ) printf ( "-1\n" );
    else
    {
        for ( int i = 1; i <= k; i ++ )
        {
            for ( int j = 1; j < 10; j ++ )
            {
                int cost = pct + ct[ j ] + ( k - i ) * minn;
                if ( cost > n ) continue;
                else ans[ i ] = j;
            }
            pct += ct[ ans[ i ] ];
        }
        EXIT:;
        for ( int i = 1; i <= k; i ++ ) printf ( "%d", ans[ i ] );
        printf ( "\n" );
    }
    
    return 0;
}