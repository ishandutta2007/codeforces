#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 100500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

pair < int, int > a[maxn];

ld calc( ld pos, int n ) {
    ld ans = 0;
    for ( int j = 0; j < n; j++ )
        ans = max( ans, 1.0L * fabs( 1.0L * a[j].f - pos ) / a[j].s );
    return ans;
}

int main()
{
    srand( time( NULL ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio( false );
    int n;
    scanf ( "%d", &n );
    for ( int j = 0; j < n; j++ )
        scanf ( "%d", &a[j].f );
    for ( int j = 0; j < n; j++ )
        scanf ( "%d", &a[j].s );
    sort( a, a + n );
    ld l = a[0].f;
    ld r = a[n - 1].f;
    int it = 200;
    while ( it-- ) {
        ld mid = ( r - l ) / 3.0L;
        if ( calc( l + mid, n ) < calc( r - mid, n ) )
            r = r - mid;
        else
            l = l + mid;
    }
    cout << fixed << setprecision( 20 ) << calc( ( l + r ) / 2.0L, n ) << endl;
    return 0;
}