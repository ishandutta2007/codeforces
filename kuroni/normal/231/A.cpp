#include <bits/stdc++.h>
using namespace std;
main()
{
    int ans = 0, a, b, c, n;
    cin>>n;
    while (n--)
    {
        cin>>a>>b>>c;
        ans += (a + b + c >= 2);
    }
    cout<<ans;
}