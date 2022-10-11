#include <bits/stdc++.h>

using namespace std;

main()
{
    int n, minn = 1e9+1, i, tmp;
    long long ans = 0;
    cin>>n;
    for (i = 0; i < n; i++)
    {
        cin>>tmp;
        ans += tmp;
        if (tmp % 2 != 0) minn = min(minn,tmp);
    }
    cout<<ans-minn*(ans % 2 != 0);
}