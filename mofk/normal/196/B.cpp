//Answer is "Yes" iff there are two distinct, reachable from start position cells, which correspond to same cell in initial labyrinth.
#include<bits/stdc++.h>
#define ff(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int MAX=1e5+5,INF=1e9;

int n,m,x,y;
char s[1505][1505];
int dx[]={-1,0,0,1},dy[]={0,-1,1,0};
bool flag=0;
ii fr[1505][1505];

bool done(int x,int y,int p,int q)
{
    return (fr[x][y]!=ii(INF,INF)&&fr[x][y]!=ii(p,q));
}

void dfs(int p,int q)
{
    int x=(p%n+n)%n,y=(q%m+m)%m;
    if(s[x][y]=='#') return;
    if(done(x,y,p,q))
    {
        flag=1;return;
    }
    if(fr[x][y]!=ii(INF,INF)) return;
    fr[x][y]=mp(p,q);
    ff(i,0,3)
    {
        int u=(p+dx[i]),v=(q+dy[i]);
        dfs(u,v);
    }
}

void init(void)
{
    cin>>n>>m;
    ff(i,0,n-1) ff(j,0,m-1) fr[i][j]=ii(INF,INF);
    ff(i,0,n-1) {cin>>s[i];ff(j,0,m-1) if(s[i][j]=='S') {x=i;y=j;}}
}

void process(void)
{
    dfs(x,y);
    cout<<(flag?"Yes":"No");
}

int main(void)
{
    init();
    process();
    return 0;
}