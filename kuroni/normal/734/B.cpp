#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;
main()
{
    ll ans, k2, k3, k5, k6, i;
    cin>>k2>>k3>>k5>>k6;
    i = min(k2, min(k5, k6));
    ans = 256 * i;
    k2 -= i; k5 -= i; k6 -= i;
    ans += 32 * min(k2, k3);
    cout<<ans;
}