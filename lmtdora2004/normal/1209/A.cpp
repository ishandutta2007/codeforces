#include <bits/stdc++.h>

using namespace std;

signed main()
{
    int n;
    cin>>n;
    int a[200];
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    int ans=0;
    sort(a+1, a+n+1);
    for(int i=1; i<=n; i++)
    {
        bool lel=1;
        for(int j=1; j<i; j++)
        {
            if(a[i]%a[j]==0)
            {
                lel=0;
            }
        }
        ans+=lel;
    }
    cout<<ans;
}