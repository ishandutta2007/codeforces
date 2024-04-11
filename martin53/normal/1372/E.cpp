#include<bits/stdc++.h>
using namespace std;

const int nmax=100+5;

int n,m;

int cnt[nmax][nmax][nmax];

int dp[nmax][nmax];

int rec(int l,int r)
{
    if(l>r)return 0;

    if(dp[l][r]!=-1)return dp[l][r];

    int ret=0;

    for(int mid=l;mid<=r;mid++)
    {
        int cur=cnt[l][mid][r];
        cur=cur*cur;

        cur=cur+rec(l,mid-1)+rec(mid+1,r);

        ret=max(ret,cur);
    }

    dp[l][r]=ret;
    return ret;
}
int main()
{
    scanf("%i%i",&n,&m);

    for(int i=1;i<=n;i++)
    {
        int sz;
        scanf("%i",&sz);

        for(int j=1;j<=sz;j++)
        {
            int l,r;
            scanf("%i%i",&l,&r);

            for(int p=1;p<=l;p++)
                for(int mid=l;mid<=r;mid++)
                    for(int q=r;q<=m;q++)
                        cnt[p][mid][q]++;
        }
    }
    memset(dp,-1,sizeof(dp));

    printf("%i\n",rec(1,m));
    return 0;
}