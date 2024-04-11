#include <bits/stdc++.h>
using namespace std;
#define MX 1000000
int lp[MX+5],dist[MX+5];
vector<int> d[MX+5],v[MX+5],pr;
vector<vector<int> > e;
int main()
{
    pr.push_back(1);
    for (int i=2;i<=MX;i++)
    {
        if (!lp[i])
        {
            pr.push_back(i);
            for (int j=i;j<=MX;j+=i)
            lp[j]=i;
        }
        d[i]=d[i/lp[i]];
        auto it=find(d[i].begin(),d[i].end(),lp[i]);
        if (it!=d[i].end())
        d[i].erase(it);
        else
        d[i].push_back(lp[i]);
    }
    int n,ans=1e9;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        if (d[a].empty())
        {
            printf("1");
            return 0;
        }
        if (d[a].size()==1)
        d[a].push_back(1);
        e.push_back({d[a][0],d[a][1]});
        v[d[a][0]].push_back(i);
        v[d[a][1]].push_back(i);
    }
    for (int i:pr)
    {
        if (i*i>MX)
        break;
        for (int j:pr)
        dist[j]=0;
        queue<pair<int,int> > q;
        for (int j:v[i])
        {
            q.push({j,(e[j][0]==i)});
            dist[e[j][0]^e[j][1]^i]=1;
        }
        while (!q.empty())
        {
            auto p=q.front();
            q.pop();
            int node=e[p.first][p.second];
            for (int u:v[node])
            {
                if (u!=p.first)
                {
                    pair<int,int> np(u,(e[u][0]==node));
                    int nnode=e[np.first][np.second];
                    if (!dist[nnode] && nnode!=i)
                    {
                        q.push(np);
                        dist[nnode]=dist[node]+1;
                    }
                    else
                    ans=min(ans,dist[node]+dist[nnode]+1);
                }
            }
        }
    }
    if (ans==1e9)
    ans=-1;
    printf("%d",ans);
}