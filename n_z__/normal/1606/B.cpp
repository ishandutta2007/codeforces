#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int ans=0;
        int now=1;
        n--;
        while(n>0)
        {
            if(now>k)ans+=(n-1)/k+1,n=0;
            else{
                ans++;
                n-=now;
                now*=2;
            }
        }
        cout<<ans<<endl;
    }
}