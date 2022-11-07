#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>

using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;
ll i[maxn], pref[maxn], suf[maxn], mn = 1, ma = - 2e9;

int main()
{
    int n, k, x, l;
    scanf ( "%d%d%d", &n, &k, &x);
    for ( l = 0; l < n; l++ )
        scanf ( "%lld", &i[l] );
    pref[0] = i[0];
    suf[n - 1]=i[n - 1];
    for ( l = 1; l < n; l++ )
        pref[l] = pref[l - 1] | i[l];
    for ( l = n - 2; l >= 0; l-- )
        suf[l] = suf[l + 1] | i[l];
    while (k--)
        mn *= x;
    ma = max( ma, ( i[0] * mn ) | suf[1] );
    ma = max( ma, ( i[n - 1] * mn ) | pref[n-2] );
    for ( l = 1; l < n - 1; l++ )
        ma = max ( ma, pref[l - 1] | ( i[l] * mn ) | suf [l + 1] );
    printf ( "%lld", ma);
    return 0;
}