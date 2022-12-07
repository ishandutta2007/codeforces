#include <bits/stdc++.h>
#define ll long long
#define M 1000
using namespace std;

int C[M+10][M+10];
ll dt[M+10];

void solve(int n,int &pos,ll &cost)
{
    pos=cost=-1;
    for(int i=0;i<=n;i++)
    {
        ll tmp=0;
        for(int j=1;j<=n;j++)
            if(j<=i) tmp+=((i-j)*4+2)*((i-j)*4+2)*dt[j];
            else tmp+=((j-i-1)*4+2)*((j-i-1)*4+2)*dt[j];
        if(cost==-1||tmp<cost)
        {
            pos=i;
            cost=tmp;
        }       
    }
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&C[i][j]);
                
        int row,col;
        ll cost=0,tc;
        
        memset(dt,0,sizeof(dt));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                dt[i]+=C[i][j];
        solve(n,row,tc);
        cost+=tc;
        
        memset(dt,0,sizeof(dt));
        for(int j=1;j<=m;j++)
            for(int i=1;i<=n;i++)
                dt[j]+=C[i][j];
        solve(m,col,tc);
        cost+=tc;
        
        printf("%I64d\n%d %d\n",cost,row,col);  
    }
    return 0;
}