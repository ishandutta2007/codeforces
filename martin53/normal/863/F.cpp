#include<bits/stdc++.h>
using namespace std;
const int nmax=50*2+5,inf=1e9;
int n;
bool can[nmax][nmax];
int flow[nmax][nmax],cost[nmax][nmax];
int parent[nmax];
int dist[nmax];
vector< pair<int/*from*/,int/*to*/> > edges;
void run()
{
for(int i=0;i<nmax;i++)
    dist[i]=inf;
dist[0]=0;
for(int i=1;i<nmax;i++)
    for(auto k:edges)
        if(flow[k.first][k.second])
        if(dist[k.first]+cost[k.first][k.second]<dist[k.second])
        {
        parent[k.second]=k.first;
        dist[k.second]=dist[k.first]+cost[k.first][k.second];
        }
}
int main()
{
cin>>n;
for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    can[i][j]=1;
int q,type,l,r,v;
cin>>q;
for(int i=1;i<=q;i++)
{
    cin>>type>>l>>r>>v;
    if(type==1)
    {
        for(int j=l;j<=r;j++)
            for(int k=1;k<v;k++)
            can[j][k]=0;
    }
    else
    {
        for(int j=l;j<=r;j++)
            for(int k=v+1;k<=n;k++)
            can[j][k]=0;
    }
}

for(int i=1;i<=n;i++)
{
    flow[0][i]=1;
    edges.push_back({0,i});
    edges.push_back({i,0});
}

for(int i=1;i<=n;i++)
{
    int num=0;
    for(int j=1;j<=n;j++)
        if(can[i][j])
        {
        flow[i][j+n]=1;
        num++;
        edges.push_back({i,j+n});
        edges.push_back({j+n,i});
        }
    if(num==0)
    {
    cout<<-1<<endl;
    return 0;
    }
}
for(int i=1;i<=n;i++)
{
    flow[i+n][2*n+1]=n;
    cost[i+n][2*n+1]=1;
    //cost[2*n+1][i+n]=-1;
    edges.push_back({i+n,2*n+1});
    //edges.push_back({2*n+1,i+n});
}
/*
    for(int p=0;p<=7;p++)
        for(int q=0;q<=7;q++)
        if(flow[p][q]||cost[p][q])
        {
        cout<<p<<" "<<q<<" -> "<<flow[p][q]<<" "<<cost[p][q]<<endl;
        }
    system("pause");
*/
int c=0;
for(int i=1;i<=n;i++)
{
    run();
    assert(dist[2*n+1]!=inf);
    int where=2*n+1;
    while(where)
    {
        //cout<<"where= "<<where<<endl;
        c=c+cost[parent[where]][where];
        flow[parent[where]][where]--;
        flow[where][parent[where]]++;
        if(where==2*n+1){cost[parent[where]][where]+=2;/*cost[where][parent[where]]=-cost[parent[where]][where];*/}
        where=parent[where];
    }
    /*
    for(int p=0;p<=7;p++)
        for(int q=0;q<=7;q++)
        if(flow[p][q]||cost[p][q])
        {
        cout<<p<<" "<<q<<" -> "<<flow[p][q]<<" "<<cost[p][q]<<endl;
        }
    system("pause");
    */
}
cout<<c<<endl;
return 0;
}