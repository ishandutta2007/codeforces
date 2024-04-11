#include<bits/stdc++.h>
using namespace std;
const int nmax=1e3+42;
int n,m;
char inp[nmax][nmax];
int dist[3][nmax][nmax];
deque< pair< pair<int/*x*/,int/*y*/>, int/*time*/> > q;
bool digit(char x)
{
    return '1'<=x&&x<='9';
}
void bfs(int ind)
{
while(q.size())
{
    pair< pair<int/*x*/,int/*y*/>, int/*time*/> now=q.front();
    q.pop_front();
    int x=now.first.first,y=now.first.second,t=now.second;
    if(dist[ind][x][y]!=-1)continue;
    if(0>=x||x>n||0>=y||y>m)continue;
    if(inp[x][y]=='#')continue;
    dist[ind][x][y]=t;
    if(digit(inp[x+1][y]))q.push_front({{x+1,y},t});
    else q.push_back({{x+1,y},t+1});

    if(digit(inp[x-1][y]))q.push_front({{x-1,y},t});
    else q.push_back({{x-1,y},t+1});

    if(digit(inp[x][y+1]))q.push_front({{x,y+1},t});
    else q.push_back({{x,y+1},t+1});

    if(digit(inp[x][y-1]))q.push_front({{x,y-1},t});
    else q.push_back({{x,y-1},t+1});
}

}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();

cin>>n>>m;
for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
    cin>>inp[i][j];
    }
memset(dist,-1,sizeof(dist));
for(char d='1';d<='3';d++)
{
for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        if(inp[i][j]==d)
            q.push_back({{i,j},0});
    bfs(d-'1');
}
int ans=-1;
for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        if(inp[i][j]!='#'&&dist[0][i][j]!=-1&&dist[1][i][j]!=-1&&dist[2][i][j]!=-1)
        {
        int s=dist[0][i][j]+dist[1][i][j]+dist[2][i][j];
        if(inp[i][j]=='.')s=s-2;
        if(ans==-1)ans=s;
        else ans=min(ans,s);
        }

cout<<ans<<endl;
return 0;
}