#include<bits/stdc++.h>
using namespace std;

const int MX=8192,INF=1e9;

int dp[MX];

int n;

vector<int> seen[MX];

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
        vector< pair<int/*start position*/,int/*xor*/> > order={};

        for(int j=0;j<MX;j++)
            if(dp[j]!=INF)order.push_back({dp[j],j});

        sort(order.begin(),order.end());
        reverse(order.begin(),order.end());

        int pointer=0;

        for(auto w:order)
        {
            int position=w.first;
            int xor_now=w.second;

            int where=upper_bound(seen[val_now].begin(),seen[val_now].end(),position)-seen[val_now].begin();
            if(where==seen[val_now].size())continue;

            where=seen[val_now][where];

            dp[xor_now^val_now]=min(dp[xor_now^val_now],where);
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