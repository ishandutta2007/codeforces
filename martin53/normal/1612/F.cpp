#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,m;

vector<int> adj[nmax];

int score(int armour,int weapon)
{
    int pos=lower_bound(adj[armour].begin(),adj[armour].end(),weapon)-adj[armour].begin();

    if(pos<adj[armour].size()&&adj[armour][pos]==weapon)return 1+armour+weapon;

    return armour+weapon;
}

int q;

vector< pair<int,int> > seen[2];

int main()
{
    scanf("%i%i",&n,&m);

    scanf("%i",&q);

    for(int i=1;i<=q;i++)
    {
        int u,v;
        scanf("%i%i",&u,&v);

        adj[u].push_back(v);
    }

    for(int i=1;i<=n;i++)sort(adj[i].begin(),adj[i].end());

    seen[0].push_back({1,1});

    for(int i=1;true;i++)
    {
        seen[i%2]={};

        for(auto w:seen[!(i%2)])
        {
            int armour=w.first,weapon=w.second;

            int cur=score(armour,weapon);

            if(min(n,cur)>armour)seen[i%2].push_back({min(n,cur),weapon});

            if(min(m,cur)>weapon)seen[i%2].push_back({armour,min(m,cur)});
        }

        sort(seen[i%2].begin(),seen[i%2].end());

        vector< pair<int,int> > compressed={};

        for(auto w:seen[i%2])
        {
            if(w.first==n&&w.second==m)
            {
                printf("%i\n",i);
                return 0;
            }

            while(compressed.size()&&compressed.back().second<=w.second)compressed.pop_back();

            compressed.push_back(w);
        }

        seen[i%2]=compressed;
    }

    return 0;
}