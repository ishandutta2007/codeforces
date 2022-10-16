#include <bits/stdc++.h>
using namespace std;
int v[300005];
int st[300005];
int dp[300005];
vector<int>precpz[300005];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,i,j,k,t;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    k=0;
    for(i=1;i<=n;++i)
    {
        int ki=k;
        while(k>0 && v[st[k]]>v[i])
        {
            if(v[st[k]]==v[st[k+1]] && k<ki)
            {

            }
            else{
            precpz[i].push_back(st[k]);
            }
            --k;
        }
        if(k)
            precpz[i].push_back(st[k]);
        st[++k]=i;
    }
    k=0;
    for(i=1;i<=n;++i)
    {
        int ki=k;
        while(k>0 && v[st[k]]<v[i])
        {
            if(v[st[k]]==v[st[k+1]] && k<ki)
            {

            }
            else{
            precpz[i].push_back(st[k]);
            }
            --k;
        }
        if(k)
            precpz[i].push_back(st[k]);
        st[++k]=i;
    }
    for(i=2;i<=n;++i)
    {
        dp[i]=1+dp[i-1];
        for(j=0;j<precpz[i].size();++j)
        {
            dp[i]=min(dp[i],1+dp[precpz[i][j]]);
        }
    }
    cout<<dp[n];
    return 0;
}