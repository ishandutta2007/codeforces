#include<bits/stdc++.h>
using namespace std;

const int nmax=3e3+42;

int n,inp[nmax];

vector<int> seen[nmax];

int dp[nmax][nmax];

int rec(int l,int r)
{
    if(l>r)return 0;

    if(dp[l][r]!=-1)return dp[l][r];

    dp[l][r]=rec(l+1,r);

    for(auto k:seen[inp[l]])
        if(l<k&&k<=r)
            dp[l][r]=max(dp[l][r],1+rec(l,k-1)+rec(k,r));

    return dp[l][r];
}

int solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)seen[i]={};
    for(int i=1;i<=n;i++)seen[inp[i]].push_back(i);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dp[i][j]=-1;

    return n-1-rec(1,n);
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        printf("%i\n",solve());
    }

    return 0;
}