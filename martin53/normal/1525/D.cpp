#include<bits/stdc++.h>
using namespace std;

const int nmax=5e3+42;

int n,inp[nmax];

vector<int> seen[2];

int dp[nmax][nmax];

int rec(int pos_0,int pos_1)
{
    if(pos_1<0)return 0;

    if(pos_0<0)return 1e9;

    if(dp[pos_0][pos_1]!=-1)return dp[pos_0][pos_1];

    int ret=rec(pos_0-1,pos_1);

    ret=min(ret,rec(pos_0-1,pos_1-1)+abs(seen[0][pos_0]-seen[1][pos_1]));

    dp[pos_0][pos_1]=ret;
    return ret;
}
int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);

        seen[inp[i]].push_back(i);
    }

    memset(dp,-1,sizeof(dp));

    printf("%i\n",rec(seen[0].size()-1,seen[1].size()-1));

    return 0;
}