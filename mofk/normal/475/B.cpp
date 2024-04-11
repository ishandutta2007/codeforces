#include<cstdio>
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
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
const ll mod=(ll)1e9+9;
int n,m,i,j,l,cnt,flag=0;
char a[25],b[25];
vi dfsnum;
vector<vi> adj;
void dfs(int x)
{
    int k; if(adj[x].size()==0) return;
    ff(k,0,adj[x].size()-1) if(dfsnum[adj[x][k]]==W)
    {
        dfsnum[adj[x][k]]=B;
        cnt++;
        dfs(adj[x][k]);
    }
}
int main(void)
{
    scanf("%d%d",&n,&m);
    dfsnum.assign(n*m,0);
    adj.assign(n*m,vi());
    scanf("%s%s",a,b);
    ff(i,0,n-1)
    {
        if(a[i]=='<') ff(j,m*i+1,m*(i+1)-1) adj[j].push_back(j-1);
        else ff(j,m*i,m*(i+1)-2) adj[j].push_back(j+1);
    }
    ff(i,0,m-1)
    {
        if(b[i]=='^') f(j,n-1) adj[j*m+i].push_back((j-1)*m+i);
        else ff(j,0,n-2) adj[j*m+i].push_back((j+1)*m+i);
    }
    ff(i,0,m*n-1)
    {
        ff(j,0,m*n-1) dfsnum[j]=W;dfsnum[i]=B;
        cnt=1;
        dfs(i);
        if(cnt!=m*n) {flag=1;break;}
    }
    if(flag) printf("NO");else printf("YES");
    return 0;
}