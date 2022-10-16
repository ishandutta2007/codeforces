#include <bits/stdc++.h>
using namespace std;
char v[203];
char a,b;
int dp[203][203][203];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t,i,j,k;
    int n;
    cin>>n>>k;
    cin>>(v+1);
    cin>>a>>b;
    int rz=0;
    for(i=1;i<n;++i)
        for(int cat=0;cat<=k;++cat)
            for(int nra=0;nra<=i;++nra)
                dp[i][cat][nra]=-80000000;
    for(i=0;i<n;++i)
    {
        for(int cat=0;cat<=k;++cat)
        {
            for(int nra=0;nra<=i;++nra)
            {
                /// dp[i][cat][nra] -> dp[i+1][cat][nra];
                char x=v[i+1];
                int totalnew=0;
                int adda=0;
                if(x==b)
                    totalnew=nra;
                if(x==a)
                    adda=1;
                dp[i+1][cat][nra+adda]=max(dp[i+1][cat][nra+adda],dp[i][cat][nra]+totalnew);
                /// dp[i][cat][nra] -> dp[i+1][cat+1][nra+1];
                if(cat==k)
                    continue;
                if(a!=b)
                {
                    dp[i+1][cat+1][nra+1]=max(dp[i+1][cat+1][nra+1],dp[i][cat][nra]);
                    /// dp[i][cat][nra] -> dp[i+1][cat+1][nra];
                    dp[i+1][cat+1][nra]=max(dp[i+1][cat+1][nra],dp[i][cat][nra]+nra);
                }
                else
                {
                    dp[i+1][cat+1][nra+1]=max(dp[i+1][cat+1][nra+1],dp[i][cat][nra]+nra);
                }
            }
        }
    }
    for(int cat=0;cat<=k;++cat)
        for(int nra=0;nra<=n;++nra)
            rz=max(rz,dp[n][cat][nra]);
    cout<<rz;
}