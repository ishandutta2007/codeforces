#include<bits/stdc++.h>
using namespace std;

const int MX=1e3+42;

int dist[MX];

queue< pair<int,int> > q;

void init()
{
    memset(dist,-1,sizeof(dist));

    q.push({1,0});

    while(q.size())
    {
        pair<int,int> tp=q.front();

        q.pop();

        if(dist[tp.first]!=-1)continue;

        dist[tp.first]=tp.second;

        for(int x=1;x<=tp.first;x++)
            if(tp.first+tp.first/x<MX)
                q.push({tp.first+tp.first/x,tp.second+1});
    }
}

int n,k;

int b[MX],c[MX];

int dp[MX*20];

int solve()
{
    scanf("%i%i",&n,&k);

    for(int i=1;i<=n;i++)scanf("%i",&b[i]);

    for(int i=1;i<=n;i++)scanf("%i",&c[i]);

    int up_to=0;

    for(int i=1;i<=n;i++)
    {
        up_to=min(k,up_to+dist[b[i]]);

        for(int j=up_to;j>=dist[b[i]];j--)
            dp[j]=max(dp[j],dp[j-dist[b[i]]]+c[i]);
    }

    int output=0;

    for(int i=0;i<=up_to;i++)
    {
        output=max(output,dp[i]);
        dp[i]=0;
    }

    return output;
}

int main()
{
    init();

    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("%i\n",solve());
    }

    return 0;
}