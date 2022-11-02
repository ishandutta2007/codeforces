#include <stdio.h>
#include <algorithm>
#include <vector>
#define For(i,n) for(i=0;i<(n);i++)

int min(int x,int y){
    return x<y?x:y;
}

void solve(int n1){
    const int mod=100000000;
    int n2,k1,k2,i,j,d[101][101][2],l;
    scanf("%d%d%d",&n2,&k1,&k2);
    For(i,n1+1)For(j,n2+1)For(l,2) d[i][j][l]=0;
    d[0][0][0]=1;
    d[0][0][1]=1;
    for(i=1;i<n1+1&&i<=k1;i++){
        d[i][0][0]=1;
        d[i][0][1]=1;
    }
    for(i=1;i<n2+1&&i<=k2;i++){
        d[0][i][1]=1;
        d[0][i][0]=1;
    }
    for(i=1;i<n1+1;i++){
        for(j=1;j<n2+1;j++){
            d[i][j][0]=d[i][j][1]=0;
            for(l=1;l<=min(k1,i);l++){
                d[i][j][0]+=d[i-l][j][1];
                d[i][j][0]%=mod;
            }
            for(l=1;l<=min(k2,j);l++){
                d[i][j][1]+=d[i][j-l][0];
                d[i][j][1]%=mod;
            }
            d[i][j][0]%=mod;
            d[i][j][1]%=mod;
        }
    }
    printf("%d",(d[n1][n2][0]+d[n1][n2][1])%mod);
}

int main() {
#pragma comment(linker, "/STACK:67108864") 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
    while(scanf("%d",&n)!=EOF){
    solve(n);
    }
    return 0;
}