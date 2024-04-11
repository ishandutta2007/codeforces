#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;
const long long inf=1e18;

vector< pair<int,int> > adj[nmax];

long long dp[nmax][2][2];
int n,m;

priority_queue< pair<long long,int> > pq;

long long outp[nmax];

int main()
{
    scanf("%i%i",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v,c;
        scanf("%i%i%i",&u,&v,&c);
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }

    for(int i=1;i<=n;i++)
    {
        dp[i][0][0]=inf;
        dp[i][0][1]=inf;
        dp[i][1][0]=inf;
        dp[i][1][1]=inf;
        outp[i]=inf;
    }

    pq.push({0,1*4});

    while(pq.size())
    {
        pair<long long,int> tp=pq.top();
        pq.pop();

        long long d=-tp.first;
        int node=tp.second/4;
        int use_0=tp.second%4/2;
        int use_1=tp.second%4%2;

        if(dp[node][use_0][use_1]!=inf)continue;

        dp[node][use_0][use_1]=d;

        //cout<<node<<" "<<use_0<<" "<<use_1<<" -> "<<d<<endl;

        outp[node]=min(outp[node],d);

        for(auto w:adj[node])
        {
            if(use_0==0)pq.push({-(d),w.first*4+2+use_1});
            if(use_1==0)pq.push({-(d+2*w.second),w.first*4+use_0*2+1});
            if(use_0==0&&use_1==0)pq.push({-(d+w.second),w.first*4+2+1});

            pq.push({-(d+w.second),w.first*4+use_0*2+use_1});
        }
    }

    for(int i=2;i<=n;i++)
        printf("%lld ",dp[i][1][1]);
    return 0;
}