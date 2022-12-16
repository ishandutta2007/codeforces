#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42,MX=52,inf=1e9+42;

int n,m;

int dp[nmax][MX];
bool been[nmax][MX];

vector< pair<int,int> > adj[nmax];

priority_queue< pair<int/*dp*/, pair<int/*node*/,char/*w*/> > > pq;

int main()
{
    scanf("%i%i%",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;

        scanf("%i%i%i",&u,&v,&w);

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<MX;j++)dp[i][j]=inf;
    }

    dp[1][0]=0;

    pq.push({0,{1,0}});

    while(pq.size())
    {
        pair<int/*dp*/, pair<int/*node*/,int/*w*/> > tp=pq.top();
        pq.pop();

        int node=tp.second.first;
        int w=tp.second.second;
        int val=-tp.first;

        if(been[node][w])continue;

        //cout<<node<<" "<<w<<" "<<val<<" "<<dp[node][w]<<endl;
        been[node][w]=1;

        if(w==0)
        {
            for(auto p:adj[node])
                if(dp[p.first][p.second]>val)
                {
                    dp[p.first][p.second]=val;
                    pq.push({-val,{p.first,p.second}});
                }
        }
        else
        {
            for(auto p:adj[node])
            {
                int score=val+(w+p.second)*(w+p.second);

                if(dp[p.first][0]>score)
                {
                    dp[p.first][0]=score;
                    pq.push({-(score),{p.first,0}});
                }
            }
        }
    }

    for(int i=1;i<=n;i++)
        if(dp[i][0]==inf)printf("-1 ");
        else printf("%i ",dp[i][0]);

    printf("\n");

    return 0;
}