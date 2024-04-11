#include<bits/stdc++.h>
using namespace std;
main()
{
    int n, b, d, tmp, ans = 0, sum = 0, i;
    cin>>n>>b>>d;
    for (i = 0; i < n; i++)
    {
        cin>>tmp;
        if (tmp <= b)
        {
            sum += tmp;
            if (sum > d)
            {
                ans++;
                sum = 0;
            }
        }
    }
    cout<<ans;
}