
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
        long long a,b,c;
        cin>>a>>b>>c;
        if(b-a==c-b)
        {
            cout<<"YES\n";
            continue;
        }
        if((b+b-a)%c==0 && (b+b-a)>0)
        {
            cout<<"YES\n";
            continue;
        }
        if((c-a)%2==0 && (c-(c-a)/2)%b==0 && (c-(c-a)/2)>0)
        {
            cout<<"YES\n";
            continue;
        }
        if((b-(c-b))%a==0 && (b-(c-b))>0)
        {
            cout<<"YES\n";
            continue;
        }
        cout<<"No\n";
    }

    return 0;
}