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
typedef pair<int,int> Pi;

int dis[15][15],deg[15];
int dp[1<<15|5],p[2010];
int ans,n,m;

int main()
{
    scanf("%d%d",&n,&m);
    int i,bit,j,k;
    for(i=0;i<n;i++)for(j=0;j<n;j++)dis[i][j]=1e8;
    for(i=0;i<m;i++){
        int u,v,l;
        scanf("%d%d%d",&u,&v,&l);
        u--,v--;
        ans += l;
        dis[v][u]=dis[u][v]=min(dis[u][v],l);
        deg[u]++,deg[v]++;
        p[i]=u;
    }
    for(i=0;i<n;i++)for(j=0;j<n;j++)for(k=0;k<n;k++)dis[j][k]=min(dis[j][i]+dis[i][k],dis[j][k]);
    for(i=0;i<m;i++)if(dis[0][p[i]]==1e8){printf("-1");return 0;}
    for(bit=1;bit<1<<n;bit++)dp[bit]=1e8+1;
    for(bit=1;bit<1<<n;bit++){
        int lastbit = 0;
        while(!(1<<lastbit&bit))lastbit++;
        for(i=lastbit+1;i<n;i++){
            if(!(bit&1<<i))continue;
            dp[bit] = min(dp[bit ^ 1<<i ^ 1<<lastbit] + dis[i][lastbit],dp[bit]);
        }
    }
    int tmp = 0;
    for(i=0;i<n;i++)if(deg[i]&1)tmp += 1<<i;
    printf("%d",ans+dp[tmp]);
    return 0;
}