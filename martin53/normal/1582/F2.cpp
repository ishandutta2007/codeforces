#include<bits/stdc++.h>
using namespace std;

const int MX=8192,INF=1e9;

int dp[MX];

int n;

vector<int> seen[MX];

pair<int,int> order[MX];
int pos_order;

int main()
{
    dp[0]=0;
    for(int i=1;i<MX;i++)dp[i]=INF;

    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);
        seen[cur].push_back(i);
    }

    for(int val_now=1;val_now<MX;val_now++)
    {
        for(int xor_now=0;xor_now<MX;xor_now++)//val_now^xor_now^xor_now=val_now
            if(dp[xor_now]!=INF)
            {
                int pos=upper_bound(seen[val_now].begin(),seen[val_now].end(),dp[xor_now])-seen[val_now].begin();

                if(pos==seen[val_now].size())continue;

                dp[xor_now^val_now]=min(dp[xor_now^val_now],seen[val_now][pos]);
            }
    }

    vector<int> outp={};
    for(int i=0;i<MX;i++)
        if(dp[i]!=INF)outp.push_back(i);

    printf("%i\n",outp.size());
    for(auto w:outp)printf("%i ",w);
    printf("\n");

    return 0;
}