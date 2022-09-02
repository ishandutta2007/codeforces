#include <stdio.h>

int n, m, b, mod;
int d[2][505][505];
int a[505];

int main(){
    scanf("%d%d%d%d",&n,&m,&b,&mod);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=m;i++){
        if(i * a[1] <= b)d[1][i][i * a[1]] = 1;
    }
    for(int i=2;i<=n;i++){
        d[1][1][a[i]] = (d[1][1][a[i]] + 1) % mod;
        for(int j=2;j<=m;j++){
            for(int k=a[i];k<=b;k++)d[1][j][k] = (d[1][j][k] + d[1][j-1][k-a[i]]) % mod;
        }
    }
    int ans = 0;
    for(int i=0;i<=b;i++)ans = (ans + d[1][m][i]) % mod;
    printf("%d",ans);
    return 0;
}