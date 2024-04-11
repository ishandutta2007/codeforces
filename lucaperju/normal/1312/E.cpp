#include <bits/stdc++.h>

using namespace std;
int dp[503][1255];
int v[503],bst[503];
int dp1[503][503];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m,i,j;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(int dst=0;dst<=n-1;++dst)
        for(int st=1;st+dst<=n;++st)
        {
            int dr=st+dst;
            if(st==dr)
            {
                dp1[st][dr]=v[st];
                continue;
            }
            for(int mij=st;mij<dr;++mij)
            {
                if(dp1[st][mij]!=0 && dp1[mij+1][dr]==dp1[st][mij])
                    dp1[st][dr]=max(1+dp1[st][mij],dp1[st][dr]);
            }
        }
    dp[1][v[1]]=1;
    bst[1]=1;
    for(i=2;i<=n;++i)
    {
        bst[i]=99999999;
        dp[i][v[i]]=bst[i-1]+1;
        bst[i]=min(bst[i],dp[i][v[i]]);
        if(dp1[1][i]!=0)
            dp[i][dp1[1][i]]=1,bst[i]=1;
        for(j=i;j>1;--j)
        {
            if(dp1[j][i] && dp[j-1][dp1[j][i]])
            {
                if(dp[i][dp1[j][i]+1]==0)
                    dp[i][dp1[j][i]+1]=dp[j-1][dp1[j][i]];
                else
                    dp[i][dp1[j][i]+1]=min(dp[j-1][dp1[j][i]],dp[i][dp1[j][i]+1]);
                bst[i]=min(bst[i],dp[i][dp1[j][i]+1]);
            }
        }
    }
    cout<<bst[n];
    return 0;
}