#include <bits/stdc++.h>
using namespace std;
int a[3], x, y, i, ans = 0;
main()
{
    cin>>y>>x;
    a[0] = a[1] = a[2] = x;
    while (a[0] != y)
    {
        a[0] = min(y,a[1]+a[2]-1);
        ans++;
        sort(a,a+3);
    }
    cout<<ans;
}