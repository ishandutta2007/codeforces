#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second

const int N = 1e5 + 10;

int a[200500];
map < int, int > cur;

int main() {
    int n, t;
    scanf ( "%d%d", &n, &t );
    for ( int j = 0; j < n; j++ )
        scanf( "%d", &a[j] );
    for ( int j = 0; j < n; j++ )
        a[j] -= 1 + j;
    int ans = 0;
    int curAns = 0;
    for ( int j = 0; j < n; j++ ) {
        int startTime = t - j - 2;
        curAns -= cur[startTime + 1];
        ++cur[a[j]];
        if ( a[j] <= startTime )
            ++curAns;
        if ( startTime < 0 )
            continue;
        ans = max( ans, curAns );
    }
    printf( "%d\n", ans );
}