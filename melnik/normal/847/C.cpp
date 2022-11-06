#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second

const int N = 1e5 + 10;

vector < char > a;
vector < char > ans;

void Bad() {
    puts( "Impossible" );
    exit( 0 );
}

int main() {
//    ifstream cin( "input.txt" );
    int n;
    long long k;
    cin >> n >> k;
    int cnt = -1;
    for ( int j = 1; j <= n; j++ )
        if ( ( ( 1LL * j * ( j + 1 ) ) / 2 ) > k ) {
            cnt = j;
            break;
        }
    if ( cnt == -1 )
        Bad();
    for ( int j = 0; j < cnt; j++ )
        a.push_back( '(' );
    for ( int j = 0; j < cnt; j++ )
        a.push_back( ')' );
    ll left = k - ( 1LL * cnt * ( cnt - 1 ) ) / 2;
    int bal = 0;
    int sz = a.size();
    for ( int j = 0; j < sz; j++ ) {
        if ( a[j] == '(' )
            ++bal;
        else
            --bal;
        ans.push_back( a[j] );
        if ( left == bal && left ) {
            ans.push_back( '(' );
            ans.push_back( ')' );
            left = 0;
        }
    }
    sz = ans.size();
    if ( sz > 2 * n )
        Bad();
    for ( int j = 0; j < sz; j++ )
        printf( "%c", ans[j] );
    for ( int j = sz; j < 2 * n; j += 2 )
        printf( "()" );
}