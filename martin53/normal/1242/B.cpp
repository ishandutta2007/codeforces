#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,m;
pair<int,int> edges[nmax];
int deg[nmax];

map< pair<int,int>,int> seen;

set<int> active;

vector< int > there[nmax];

int parent[nmax];

int main()
{
    scanf("%i%i",&n,&m);
    for(int i=1;i<=n;i++)deg[i]=n-1;

    for(int i=1;i<=m;i++)
    {
        scanf("%i%i",&edges[i].first,&edges[i].second);

        if(edges[i].first>edges[i].second)swap(edges[i].first,edges[i].second);

        deg[edges[i].first]--;
        deg[edges[i].second]--;

        seen[{edges[i].first,edges[i].second}]=1;
    }

    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        there[i]={i};
        active.insert(i);
    }

    for(int i=2;i<=n;i++)
    {
        set<int> to_remove={};

        for(auto k:active)
        {
            if(k>=i)break;
            if(k==parent[i])continue;

            bool ok=0;
            for(auto now:there[k])
                if(seen.count({now,i})==0)
                {
                    ok=1;
                    break;
                }
            if(ok)
            {
                int bigger=k,smaller=parent[i];


                if(there[bigger].size()<there[smaller].size())swap(bigger,smaller);

                for(auto p:there[smaller])
                    {
                        there[bigger].push_back(p);
                        parent[p]=bigger;
                    }

                to_remove.insert(smaller);
            }
        }
        for(auto k:to_remove)
            active.erase(k);
    }

    set<int> s={};
    for(int i=1;i<=n;i++)
        s.insert(parent[i]);

    printf("%i\n",s.size()-1);
    return 0;
}