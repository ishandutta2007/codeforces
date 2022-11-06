#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 100500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

set < int > a;

int main()
{
    srand( time( NULL ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio( false );
    int n;
    scanf ( "%d", &n );
    int ans = 0;
    for ( int j= 0; j < 2 * n; j++ ) {
        int x;
        scanf ( "%d", &x );
        if ( a.find( x ) != a.end() )
            a.erase( x );
        else
            a.insert( x );
        ans = max( ans, (int)a.size() );
    }
    printf ( "%d\n", ans );
    return 0;
}