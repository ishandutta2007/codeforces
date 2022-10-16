#include<cstdio>
#include<cassert>
#include<algorithm>
#include<vector>
#include<cmath>
#include<iostream>
#include<cstring>
#define f(i,n) for(int i=1;i<=n;i++)
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define F(i,n) for (int i=n;i>=1;i--)
#define FF(i,a,b) for(int i=a;i>=b;i--)
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
typedef pair<char,ii> pcii;
const int MAX=1e5+5; const ll mod=1e9+7;

vector<vi> adj;vi color;
char s[505][505];
int n,m,x[]={-1,0,0,1},y[]={0,-1,1,0},root=0;
vector<pcii> ans;
void dfs(int i)
{
    int flag=0;
    color[i]=B;if(!root) flag=1;
    ans.pb(pcii('B',ii(i/m+1,i%m+1)));
    if(!adj[i].empty()) ff(j,0,adj[i].size()-1) if(color[adj[i][j]]==W) {root=0;dfs(adj[i][j]);}
    if(flag)
    {
        ans.pb(pcii('D',ii(i/m+1,i%m+1)));
        ans.pb(pcii('R',ii(i/m+1,i%m+1)));
    }
}

int main(void)
{
    scanf("%d%d",&n,&m);
    adj.assign(m*n,vi());
    color.assign(m*n,W);
    ff(i,0,n-1) scanf("%s",s[i]);
    ff(i,0,n-1) ff(j,0,m-1) if(s[i][j]=='.')
    {
        ff(k,0,3) if(s[i+x[k]][j+y[k]]=='.') adj[i*m+j].pb((i+x[k])*m+j+y[k]);
    }
    ff(i,0,m*n-1) if(s[i/m][i%m]=='.'&&color[i]==W) {root=1;dfs(i);}
    printf("%d\n",ans.size());
    if(!ans.empty()) ff(i,0,ans.size()-1) printf("%c %d %d\n",ans[i].fi,ans[i].se.fi,ans[i].se.se);
    return 0;
}