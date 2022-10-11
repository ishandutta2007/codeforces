#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;
main()
{
    int n, k, i, a[500];
    ll ans = 0;
    cin>>n>>k;
    for (i = 0; i < n; i++) cin>>a[i];
    for (i = 1; i < n; i++)
        if (a[i-1] + a[i] < k)
        {
            ans += k - a[i-1] - a[i];
            a[i] = k - a[i-1];
        }
    cout<<ans<<'\n';
    for (i = 0; i < n; i++) cout<<a[i]<<" ";
}