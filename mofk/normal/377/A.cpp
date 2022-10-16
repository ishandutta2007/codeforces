#include<cstdio>
#include<cassert>
#include<algorithm>
#include<vector>
#include<cmath>
#include<iostream>
#include<cstring>
#define f(i,n) for(i=1;i<=n;i++)
#define ff(i,a,b) for(i=a;i<=b;i++)
#define F(i,n) for (i=n;i>=1;i--)
#define FF(i,a,b) for(i=a;i>=b;i--)
#define fi first
#define se second
#define B 1
#define W -1
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int m,n,i,j,k,cnt=0;
vi dfsnum;
char maze[505][505];
vector<vi> adj;
int dfscnt;
void dfs(int x)
{
    int i;
    dfsnum[x]=B;
    ff(i,0,(int)adj[x].size()-1) if(dfsnum[adj[x][i]]==W) {
        dfs(adj[x][i]);
    }
    if(cnt<k) {maze[x/m][x%m]='X';cnt++;}
}
int main(void)
{
    //freopen("1.inp","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    adj.assign(m*n,vi());
    ff(i,0,n-1) scanf("%s",maze[i]);
    ff(i,0,n-1) ff(j,0,m-1) if(maze[i][j]=='.')
    {
        if(i>0&&maze[i-1][j]=='.') adj[i*m+j].pb((i-1)*m+j);
        if(i<n-1&&maze[i+1][j]=='.') adj[i*m+j].pb((i+1)*m+j);
        if(j>0&&maze[i][j-1]=='.') adj[i*m+j].pb(i*m+j-1);
        if(j<m-1&&maze[i][j+1]=='.') adj[i*m+j].pb(i*m+j+1);
    }
    ff(i,0,n-1) {ff(j,0,m-1) if(maze[i][j]=='.')
    {
        dfsnum.assign(n*m,W);
        dfs(i*m+j);

    ff(i,0,n-1) printf("%s\n",maze[i]);
    return 0;break;
    }}
    ff(i,0,n-1) printf("%s\n",maze[i]);
    return 0;
}