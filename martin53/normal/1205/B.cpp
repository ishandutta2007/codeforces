#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42,LIM=130,inf=1e9;
int n;
long long inp[nmax];

vector<int> seen[61],adj[nmax];

queue< pair<int/*to*/,int/*dist*/> > q,idle;

vector< pair<int,int> > edges;

int dist[nmax];
bool eq(int a,int b,pair<int,int> c)
{
    if(c==make_pair(a,b))return 1;
    if(c==make_pair(b,a))return 1;
    return 0;
}
int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&inp[i]);


    for(int i=1;i<=n;i++)
    for(int bit=0;bit<60;bit++)
        if(((1LL<<bit)&inp[i]))
        {
            seen[bit].push_back(i);
        }

    for(int bit=0;bit<60;bit++)
        if(seen[bit].size()>=3)
        {
            printf("3\n");
            return 0;
        }
        else if(seen[bit].size()==2)
        {
            //cout<<seen[bit][0]<<" "<<seen[bit][1]<<endl;
            adj[seen[bit][0]].push_back(seen[bit][1]);
            adj[seen[bit][1]].push_back(seen[bit][0]);
            edges.push_back({seen[bit][0],seen[bit][1]});
        }


    int shortest=inf;
    for(auto k:edges)
        {
            q=idle;
            for(int j=1;j<=n;j++)dist[j]=inf;
            q.push({k.first,0});
            while(q.size())
            {
                pair<int/*to*/,int/*dist*/> now=q.front();
                q.pop();

                int to=now.first;
                int d=now.second;

                //cout<<k.first<<" "<<k.second<<" "<<to<<" "<<d<<endl;

                if(dist[to]>=d)dist[to]=d;
                else continue;

                for(auto e:adj[to])
                    if(eq(to,e,k)==0)
                    {
                        q.push({e,d+1});
                    }
            }
            shortest=min(shortest,dist[k.second]+1);
        }

    if(shortest!=inf)printf("%i\n",shortest);
    else printf("-1");
    return 0;
}