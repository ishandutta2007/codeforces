#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
char str[30][200010];
int dp[30][1500010],col[200010],ans=1000000000;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%s",str[i]);
    for(int i=0;i<m;i++)
    {
        int k=0;
        for(int j=0;j<n;j++)
            k=k<<1|(str[j][i]-'0');
        col[i]=k;
    }
    for(int i=0;i<m;i++) dp[0][col[i]]++;
    for(int i=1;i<=n;i++)
        for(int j=0;j<(1<<n);j++)
        {
            //for(int p=0;p<n;p++)
            //    for(int k=i-1;k>=0;k--)
            //        if((i-k)&1) dp[i][j]+=dp[k][j^(1<<p)];
            //        else dp[i][j]-=dp[k][j];
            for(int k=0;k<n;k++)
                dp[i][j]+=dp[i-1][j^(1<<k)];
            if(i!=1) dp[i][j]+=(i-2-n)*dp[i-2][j];
            dp[i][j]/=i;
        }
    for(int j=0;j<(1<<n);j++)
    {
        int res=0;
        for(int i=0;i<=n;i++)
            res+=min(i,n-i)*dp[i][j];
        ans=min(ans,res);
    }
    printf("%d\n",ans);
    return 0;
}