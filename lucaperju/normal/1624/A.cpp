
#include <bits/stdc++.h>

using namespace std;
int n,a[5005],dp[5005],nr[5005],ma,x;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int mx=0,mn=1000000000;
        for(int i=1;i<=n;++i)
        {
            int a;
            cin>>a;
            mn=min(mn,a);
            mx=max(mx,a);
        }
        cout<<mx-mn<<'\n';
    }

    return 0;
}