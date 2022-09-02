#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int dp[1<<24],bk[1<<24];

int x[25],y[25],dis[25][25],dis2[25];
int sx,sy,n;

inline int sqa(int x){return x*x;}

int dfs(int x)
{
    if(x==(1<<n)-1)return 0;
    if(dp[x]<1e9)return dp[x];
    int i,j;
    for(i=0;i<n;i++){
        if(x&1<<i)continue;
        for(j=i;j<n;j++){
            if(x&1<<j)continue;
            int t=x|1<<i|1<<j;
            int y=dfs(t)+dis2[i]+dis2[j]+dis[i][j];
            if(dp[x]>y)dp[x]=y,bk[x]=t;
        }
        break;
    }
    return dp[x];
}

int main(){
    scanf("%d%d%d",&sx,&sy,&n);
    int i;
    for(i=0;i<n;i++){
        scanf("%d%d",x+i,y+i);
        x[i]-=sx,y[i]-=sy;
    }
    int j,b;
    for(i=0;i<n;i++)for(j=0;j<n;j++)dis[i][j]=sqa(abs(x[i]-x[j]))+sqa(abs(y[i]-y[j]));
    for(i=0;i<n;i++)dis2[i]=sqa(abs(x[i]))+sqa(abs(y[i]));
    for(b=0;b<(1<<n);b++)dp[b]=1e9;
    dfs(0);
    printf("%d\n0 ",dp[0]);
    int now = 0;
    while(now+1!=(1<<n)){
        int tmp = now^bk[now];
        for(i=0;i<n;i++){
            if(tmp&(1<<i))printf("%d ",i+1);
        }
        now=bk[now];
        printf("0 ");
    }
    return 0;
}