#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<ll,ll> Pi;
typedef pair<int,pair<ll,ll> > Pii;

ll x[100010], y[100010];
int up[100010][20];
int dep[100010];
vector <int> dn[100010];

void dfs(int x)
{
    for(int i=0;i<dn[x].size();i++){
        dep[dn[x][i]] = dep[x] + 1;
        for(int j=1;j<=17;j++)up[dn[x][i]][j] = up[ up[dn[x][i]][j-1] ][j-1];
        dfs(dn[x][i]);
    }
}

int LCA(int x,int y)
{
    if(dep[x] < dep[y])swap(x,y);
    for(int i=0;i<=17;i++)if(1<<i&(dep[x]-dep[y]))x=up[x][i];
    for(int i=17;i>=0;i--){
        if(up[x][i] != up[y][i])x = up[x][i], y = up[y][i];
    }
    return x==y ? x : up[x][0];
}

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++)scanf("%lld%lld",x+i,y+i);
    vector <Pii> v;
    v.push_back(Pii(n,Pi(x[n],y[n])));
    for(i=n-1;i;i--){
        while(v.size() > 1 && (v[v.size()-2].Y.Y - v.back().Y.Y) * (v.back().Y.X - x[i]) > (v.back().Y.Y - y[i]) * (v[v.size()-2].Y.X - v.back().Y.X)){
            v.pop_back();
        }
        up[i][0] = v.back().X;
        dn[v.back().X].push_back(i);
        v.push_back(Pii(i,Pi(x[i], y[i])));
    }
    dfs(n);
    int q;
    scanf("%d",&q);
    while(q--){
        int x, y;
        scanf("%d%d",&x,&y);
        printf("%d ",LCA(x,y));
    }
    return 0;
}