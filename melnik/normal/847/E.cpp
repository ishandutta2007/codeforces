#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second

const int N = 1e5 + 10;

char t[100500];

set < int > cur;

bool correct( int x, int n ) {
    for ( int j = 0; j < n; j++ )
        if ( t[j] == '*' )
            cur.insert( j );
    for ( int j = 0; j < n; j++ ) {
        if ( t[j] != 'P' )
            continue;
        if ( cur.empty() )
            return true;
        int firstPos = *cur.begin();
        if ( abs( firstPos - j ) > x )
            continue;
        if ( firstPos > j ) {
            while ( !cur.empty() )
                if ( *cur.begin() <= j + x )
                    cur.erase( cur.begin() );
                else
                    break;
        }
        else {
            int len1 = 2 * ( j - firstPos );
            int left1 = max( 0, x - len1 );
            int left2 = ( x - len1 / 2 ) / 2;
            int left = max( left1, left2 );
            while ( !cur.empty() )
                if ( *cur.begin() <= j + left )
                    cur.erase( cur.begin() );
                else
                    break;
        }
    }
    return cur.empty();
}

int main() {
//    ifstream cin( "input.txt" );
    int n;
    scanf ( "%d\n", &n );
    gets( t );
    int l = 0;
    int r = 2 * 100500;
    while ( r - l ) {
        int mid = ( l + r ) >> 1;
        if ( !correct( mid, n ) )
            l = mid + 1;
        else
            r = mid;
    }
    printf( "%d\n", l );
}