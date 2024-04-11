#include<bits/stdc++.h>
using namespace std;
const int lim=1e4/*1*/,stop=128/*5*/,nmax=5e5+42;
int n,m;
bitset<lim> edge[lim];
vector< vector<int> > outp;
bitset<nmax> been,emp;
void dfs(int node)
{
    if(been[node])return;
    been[node]=1;
    outp[outp.size()-1].push_back(node);
    for(int i=1;i<=n;i++)
        if(edge[node][i]&&been[i]==0)dfs(i);
}
void print()
{
    printf("%i\n",outp.size());
    for(auto k:outp)
    {
        printf("%i",k.size());
        for(auto p:k)
            printf(" %i",p);
        printf("\n");
    }
    exit(0);
}
void slow()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        edge[i][j]=1;
    int x,y;
    for(int i=1;i<=m;i++)
    {
        scanf("%i%i",&x,&y);
        edge[x][y]=0;
        edge[y][x]=0;
    }
    for(int i=1;i<=n;i++)
        if(been[i]==0)
        {
        outp.push_back({});
        dfs(i);
        }
    print();
}
bool out[nmax];
vector<int> adj[nmax];
vector<int> now;
int NOW_SZ=0;
void second_dfs(int node)
{
    //cout<<"node= "<<node<<endl;
    if(been[node]||out[node])return;
    if(NOW_SZ>=stop)return;
    been[node]=1;
    now.push_back(node);
    NOW_SZ++;
    int pos=0,SZ=adj[node].size();
    for(int i=1;i<=n;i++)
    {
        if(NOW_SZ>=stop)break;
        if(pos<SZ&&adj[node][pos]==i)
        {
        pos++;
        continue;
        }
        second_dfs(i);
    }
}
int main()
{
scanf("%i%i",&n,&m);
if(n<lim)slow();
int x,y;
for(int i=1;i<=m;i++)
{
    scanf("%i%i",&x,&y);
    adj[x].push_back(y);
    adj[y].push_back(x);
}
for(int i=1;i<=n;i++)sort(adj[i].begin(),adj[i].end());

for(int i=1;i<=n;i++)
    if(out[i]==0&&n-adj[i].size()<=stop)
    {
    //cout<<"i= "<<i<<endl;
    second_dfs(i);
        if(NOW_SZ<stop&&NOW_SZ)
        {
        outp.push_back(now);
        for(auto k:now)out[k]=1;
        }
    NOW_SZ=0;
    now={};
    been=emp;
    }

for(int i=1;i<=n;i++)
    if(out[i]==0)now.push_back(i);
if(now.size())outp.push_back(now);
print();
return 0;
}