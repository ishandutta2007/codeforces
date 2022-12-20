#include<bits/stdc++.h>
using namespace std;
const int nmax=2e3+42;
int n,m;
char inp[nmax][nmax];
queue< pair<int,int> > q;
int parent[nmax*nmax];
int SZ[nmax*nmax];
int get(int i,int j)
{
     return j+(i-1)*m;
}
int root(int x)
{
     if(parent[x]==x)return x;
     parent[x]=root(parent[x]);
     return parent[x];
}
void unite(int a,int b)
{
    if(a==b)return;
    if(SZ[a]<SZ[b])
    {
        SZ[b]=SZ[b]+SZ[a];
        parent[a]=b;
    }
    else
    {
        SZ[a]=SZ[a]+SZ[b];
        parent[b]=a;
    }
}
bool been[nmax][nmax];
int pos=0;
pair<int,int> re[nmax*nmax];
void dfs(int i,int j)
{
    if(i==0||i==n+1||j==0||j==m+1)return;
    if(been[i][j])return;
    re[++pos]={i,j};
    been[i][j]=1;
    if(inp[i][j]=='*'){q.push({i,j});return;}
    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j-1);
    dfs(i,j+1);
}
void dfs_back(int u)
{
    int j=u%m;
    if(j==0)j=m;
    int i=(u-j)/m+1;
    dfs(i,j);
    for(int j=1;j<=pos;j++)
        been[re[j].first][re[j].second]=0;
    pos=0;
}
bool good(int x,int y)
{
    int free=0;
    set<int> q={};
    if(inp[x+1][y]=='.'){free++;q.insert(root(get(x+1,y)));}
    if(inp[x-1][y]=='.'){free++;q.insert(root(get(x-1,y)));}
    if(inp[x][y+1]=='.'){free++;q.insert(root(get(x,y+1)));}
    if(inp[x][y-1]=='.'){free++;q.insert(root(get(x,y-1)));}
    if(free==q.size())return 0;
    for(auto k:q)
        {
        int u=root(k),v=root(get(x,y));
        if(u==v)continue;
        if(SZ[u]<SZ[v])dfs_back(u);
        else dfs_back(v);
        unite(u,v);
        }
    return 1;
}

void run()
{

for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        if(inp[i][j]=='*')q.push({i,j});

while(q.size())
{
    int x=q.front().first,y=q.front().second;
    q.pop();
    if(x==0||x==n+1||y==0||y==m+1)continue;
    if(inp[x][y]=='.')continue;
    if(good(x,y)==0)continue;
    inp[x][y]='.';
    q.push({x+1,y});
    q.push({x-1,y});
    q.push({x,y+1});
    q.push({x,y-1});
}

}

int main()
{
scanf("%i%i",&n,&m);
char c;
for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        scanf("%c",&c);
        if(c!='.'&&c!='*')j--;
        else inp[i][j]=c;
        parent[get(i,j)]=get(i,j);
        SZ[get(i,j)]=1;
    }
for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        if(inp[i][j]=='.'&&inp[i+1][j]=='.')
        {
            unite(root(get(i+1,j)),root(get(i,j)));
        }

        if(inp[i][j]=='.'&&inp[i][j+1]=='.')
        {
            unite(root(get(i,j+1)),root(get(i,j)));
        }
    }
run();

for(int i=1;i<=n;i++)
{
    for(int j=1;j<=m;j++)printf("%c",inp[i][j]);
    printf("\n");
}
return 0;
}