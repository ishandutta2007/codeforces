#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 200100;

int n, i[maxn];
ld b[maxn];

ld max_search ( ld x ){
    ld ma, mi, zn, ans = -2e9;
    zn = i[0] - x;
    ma = i[0] - x;
    mi = min ( (ld) 0, i[0] - x );
    for ( int k = 1; k < n; k++){
        zn += i[k] - x;
        ma = max ( ma, zn - mi );
        mi = min ( mi, zn );
    }
    ans = ma;
    zn = x - i[0];
    ma = x - i[0];
    mi = min ( (ld) 0, x- i[0] );
    for ( int k = 1; k < n; k++){
        zn -= i[k] - x;
        ma = max ( ma, zn - mi );
        mi = min ( mi, zn );
    }
    return max ( ans, ma );
}

int main()
{
    int k;
    cin >> n;
    for ( k = 0; k < n; k++)
        cin >> i[k];
    ld l = -2e5, r = 2e5;
    while ( abs( l - r) > 1e-15){
        ld third = ( r - l ) / 3.0;
        if ( max_search( l + third) > max_search (r - third ) )
            l += third; else
            r -= third;
    }
    cout << setprecision( 35 ) << max_search( l );
    return 0;
}