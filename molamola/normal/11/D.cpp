#include<stdio.h>

long long dp[1<<19][19],ans;
int n,m;
int gr[19][19];

int main()
{
    scanf("%d%d",&n,&m);
    int bit,i,j;
    for(i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        x--,y--;
        gr[x][y]=gr[y][x]=1;
        if(x>y)dp[1<<y][x]=1;
        else dp[1<<x][y]=1;
    }
    for(bit=1;bit<(1<<n);bit++){
        int lastbit = 0;
        while(!(1<<lastbit&bit))lastbit++;
        for(i=lastbit+1;i<n;i++){
            if(bit&1<<i)continue;
            for(j=lastbit+1;j<n;j++){
                if(gr[i][j])dp[bit|1<<i][j] += dp[bit][i];
            }
            if(gr[lastbit][i])ans += dp[bit][i];
        }
    }
    printf("%lld",(ans-m)>>1);
    return 0;
}