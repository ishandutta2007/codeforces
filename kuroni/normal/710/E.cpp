#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
main()
{
    ll n, x, y, i, a[10000000];
    cin>>n>>x>>y;
    for (a[0] = 0, i = 1; i <= n; i++) a[i] = min(a[i-1] + x, a[(i+1)/2] + y +(i%2)*x);
    printf("%I64d",a[n]);
}