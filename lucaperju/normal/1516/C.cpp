#include <bits/stdc++.h>
using namespace std;
int v[100];
int dp[200003];
int main()
{
    ios_base::sync_with_stdio(false);
    int q,t,m,i,j;
    int n;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    int s=0;
    for(i=1;i<=n;++i)
        s+=v[i];
    if(s%2==1)
    {
        cout<<0;
        return 0;
    }
    s/=2;
    dp[0]=1;
    for(i=1;i<=n;++i)
    {
        for(j=s;j>=0;--j)
        {
            if(dp[j])
                dp[j+v[i]]=1;
        }
    }
    if(dp[s]==0)
    {
        cout<<0;
        return 0;
    }
    cout<<"1\n";
    while(1)
    {
        int ok=1;
        for(i=1;i<=n;++i)
            if(v[i]%2)
                ok=0;
        if(ok==0)
            break;
        for(i=1;i<=n;++i)
            v[i]/=2;
    }
    for(i=1;i<=n;++i)
    {
        if(v[i]%2)
        {
            cout<<i<<'\n';
            return 0;
        }
    }
	return 0;
}