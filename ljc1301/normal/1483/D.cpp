#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=0x3fffffffffffffffll;
const int maxn=606;
const int maxm=maxn*maxn;
int n,m,u[maxm],v[maxm];
ll dis[maxn][maxn],c[maxm],f[maxn][maxn]; // x-...-u-v-...-y x-u+u-v<=f[x][v] x-u+u-v+v-y<=l
int main()
{
    int i,j,k,q,x,y,ans=0;
    ll l;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            dis[i][j]=(i==j)?0:inf;
    for(i=0;i<m;i++)
        scanf("%d%d%lld",&u[i],&v[i],&c[i]),dis[v[i]][u[i]]=dis[u[i]][v[i]]=c[i];
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            f[i][j]=-inf;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d%lld",&x,&y,&l);
        for(i=1;i<=n;i++)
            f[x][i]=max(f[x][i],l-dis[i][y]);
    }
    for(i=0;i<m;i++)
    {
        for(x=1;x<=n;x++)
            if(dis[x][u[i]]+c[i]<=f[x][v[i]] || dis[x][v[i]]+c[i]<=f[x][u[i]])
                break;
        if(x<=n) ans++;
    }
    printf("%d\n",ans);
    return 0;
}