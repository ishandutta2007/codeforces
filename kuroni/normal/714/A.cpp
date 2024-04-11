#include <bits/stdc++.h>
using namespace std;
main()
{
    long long l1, l2, r1, r2, k, n;
    cin>>l1>>r1>>l2>>r2>>k;
    l1 = max(l1,l2);
    r1 = min(r1,r2);
    n = r1 - l1 + 1;
    if ((k >= l1) && (k <= r1)) n--;
    cout<<((n<0)?0:n);
}