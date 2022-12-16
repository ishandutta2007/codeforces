#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int colour[nmax];
vector<int> adj[nmax];
int deg[nmax];
int n;

queue<int> leaf[3],idle;

int exact(int start)
{
    leaf[0]=idle;
    leaf[1]=idle;
    leaf[2]=idle;

    for(int i=1;i<=n;i++)deg[i]=0;

    for(int i=1;i<=n;i++)
        for(auto j:adj[i])
            deg[j]++;

    for(int i=1;i<=n;i++)
        if(deg[i]==1)leaf[colour[i]].push(i);

    int ret=0;

    while(leaf[0].size()||leaf[1].size()||leaf[2].size())
    {
        while(leaf[start].size()||leaf[0].size())
        {
            int cur;

            if(leaf[start].size())
            {
                cur=leaf[start].front();
                leaf[start].pop();
            }
            else
            {
                cur=leaf[0].front();
                leaf[0].pop();
            }

            for(auto k:adj[cur])
            {
                deg[k]--;

                if(deg[k]==1)leaf[colour[k]].push(k);
            }
        }

        start=3-start;
        ret++;
    }
    return ret;
}
int solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&colour[i]);

    for(int i=1;i<=n;i++)adj[i]={};

    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%i%i",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(n==1)return 1;

    return min(exact(1),exact(2));
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