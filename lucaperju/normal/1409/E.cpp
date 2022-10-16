#include <bits/stdc++.h>
using namespace std;
int v[200005];
int pzst[200005];
int dp[200005];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t,i,j,k;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n>>k;
        for(i=1;i<=n;++i)
            cin>>v[i];
        sort(v+1,v+n+1);
        for(i=1;i<=n;++i)
            cin>>j;
        if(n<=2)
        {
            cout<<n<<'\n';
            continue;
        }
        pzst[1]=1;
        int st=1,dr=2;
        while(dr<=n)
        {
            while(v[dr]-v[st]>k)
                ++st;
            pzst[dr]=st;
            ++dr;
        }
        dp[1]=1;
        int rz=1;
        for(i=2;i<=n;++i)
            dp[i]=max(dp[i-1],i-pzst[i]+1);
        for(i=2;i<=n;++i)
            rz=max(rz,dp[pzst[i]-1]+i-pzst[i]+1);
        cout<<rz<<'\n';
    }
}