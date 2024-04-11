#include <bits/stdc++.h>
using namespace std;
int dp[403][403];
char a[403],b[403];
int nxt[405][30];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,m,i,j,t;
    cin>>t;
    while(t--)
    {
        cin>>(a+1)>>(b+1);
        n=strlen(a+1);
        m=strlen(b+1);
        for(j=1;j<=26;++j)
            nxt[n+1][j]=nxt[n+2][j]=n+1;
        for(i=n;i>=0;--i)
        {
            for(j=1;j<=26;++j)
                nxt[i][j]=nxt[i+1][j];
            if(i!=0)
                nxt[i][a[i]-'a'+1]=i;
        }
        int ok=0;
        for(int cat=1;cat<=m;++cat)
        {
            for(i=0;i<=cat;++i)
                for(j=cat;j<=m;++j)
                    dp[i][j]=0;
            for(j=cat+1;j<=m;++j)
            {
                /// dp[0][j]
                dp[0][j]=nxt[dp[0][j-1]+1][b[j]-'a'+1];
            }
            for(i=1;i<=cat;++i)
            {
                /// dp[i][0]
                dp[i][cat]=nxt[dp[i-1][cat]+1][b[i]-'a'+1];
                for(j=cat+1;j<=m;++j)
                {
                    /// dp[i][j]
                    dp[i][j]=min(nxt[dp[i-1][j]+1][b[i]-'a'+1],nxt[dp[i][j-1]+1][b[j]-'a'+1]);
                }
            }
            if(dp[cat][m]<=n)
                ok=1;
        }
        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}